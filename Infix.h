#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

// PRE: A string infix
// POST: Returns the postFix equivalent
string convert(string infix);

// PRE: An operator character and reference to postFix string
// Post: Appends operators from the stack correctly to postFix
void processOperator(char op, string &postFix);

// PRE: An operator
// POST: Returns an int value representing the precedence of PE/MD/AS
int getPrecedence(char op);

// PRE: A character
// POST: Returns true if the character is an operator, false otherwise
bool isOperator(char ch);

// PRE: A character
// POST: Returns true if the character is a parenthesis, false otherwise 
bool isParenthesis(char ch);

// PRE: A parenthesis character and reference to postFix string
// POST: Appends to the postFix string based on the structure of parenthesis
void processParenthesis(char ch, string &postFix);

// PRE: The inFix string
// POST: Returns true if the string has balanced parenthsis counts, false otherwise. 
bool isBalanced(string& inFix);
