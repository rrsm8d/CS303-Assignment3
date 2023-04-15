#include "Infix.h"

stack<char> operatorsStack; // Global stack

string convert(string infix)
{
	if (!isBalanced(infix))
	{
		return "---";
	}
	string readNum = "";
	string postFix = "";
	
	// Go through entire infix string
	for (char ch : infix)
	{
		if (isOperator(ch)) // If its an operator, process it to add to the stack
		{
			processOperator(ch, postFix);
		}
		else if (isParenthesis(ch)) // If its a parenthsis, process it
		{
			processParenthesis(ch, postFix);
		}
		else if (ch != ' ') // Must be a number then.
		{
			postFix += ch;
		}
		else cerr << "ERROR!!!!!!!!!!!" << endl; // Temporary
	}
	while (operatorsStack.size() != 0) // Append any leftover operators before returning
	{
		postFix += operatorsStack.top();
		operatorsStack.pop();
	}
	return postFix;
}

void processOperator(char op, string &postFix)
{
	// If empty, just add it, no need to check, just add it
	if (operatorsStack.size() == 0)
	{
		operatorsStack.push(op);
	}
	else if (getPrecedence(op) > getPrecedence(operatorsStack.top())) // If the NEW operator has a GREATER precedence, push NEW operator to stack
	{
		operatorsStack.push(op);
	}
	else // if it has LESS or EQUAL precedence than the OLD operator, move the stack to the string and append the NEW operator to the postFix
	{
		while (operatorsStack.size() >= 1 && getPrecedence(op) <= getPrecedence(operatorsStack.top()))
		{
			postFix += operatorsStack.top();
			operatorsStack.pop();
		}
		operatorsStack.push(op);
	}
}

int getPrecedence(char op)
{
	switch (op) {
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	case '%':
		return 2;
		break;
	default:
		return -1;
	}
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
	{
		return true;
	}
	else return false;
}

bool isParenthesis(char ch)
{
	if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
	{
		return true;
	}
	else return false;
}

void processParenthesis(char ch, string &postFix)
{
	if (ch == '(' || ch == '[' || ch == '{')
	{
		operatorsStack.push(ch);
	}
	if (ch == ')')
	{
		while (operatorsStack.top() != '(' && operatorsStack.size() >= 1) // Go through the stack until its empty or finds the opening parenthesis
		{
			postFix += operatorsStack.top();
			operatorsStack.pop();
			if (operatorsStack.top() == '(') // Ensure these are not written to the postFix expression
			{
				operatorsStack.pop();
				break;
			}
		}
	} else if (ch == ']')
	{
		while (operatorsStack.top() != '[' || operatorsStack.size() >= 1)
		{
			postFix += operatorsStack.top();
			operatorsStack.pop();
			if (operatorsStack.top() == '[')
			{
				operatorsStack.pop();
				break;
			}
		}
	} else 	if (ch == '}')
	{
		while (operatorsStack.top() != '{' || operatorsStack.size() >= 1)
		{
			postFix += operatorsStack.top();
			operatorsStack.pop();
			if (operatorsStack.top() == '{')
			{
				operatorsStack.pop();
				break;
			}
		}
	}
}

bool isBalanced(string& inFix)
{
	std::map<char, int> count;

	count['('] = 0;
	count['['] = 0;
	count['{'] = 0;
	count[')'] = 0;
	count[']'] = 0;
	count['}'] = 0;

	for (auto ch : inFix)
	{
		if (isParenthesis(ch))
		{
			count[ch]++;
		}
	}

	// Validation
	if (count['('] == count[')'] && count['['] == count[']'] && count['{'] == count['}'])
	{
		return true;
	}
	else
	{
		cerr << "This input does not have balanced parenthesis" << endl;
		return false;
	}

}