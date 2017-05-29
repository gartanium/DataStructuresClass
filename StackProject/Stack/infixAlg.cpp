/***********************************************************************
* Source File:
*    Infix
* Summary:
*    This class contains the definition for a function that uses the stack
*    class to convert an infix expression into a post fix expression.
*
* Author
*    Matthew Brown
************************************************************************/

#include "stack.h"
#include <iostream>
#include <string>
#include "infixAlg.h"

InfixAlg::~InfixAlg()
{
}

string InfixAlg::to_postFix()
{
	char token, topToken; // character in exp; token on top of opStack;
	Stack<char> opStack; // stack of operators
	string postfixExp = ""; // postfix expression
	const string BLANK = " ";
	const string EMPTY = "";
	for (int i = 0; i < exp.length(); i++)
	{
		token = exp[i];
		switch (token)
		{
		case '.': 
			if (i > 1 && !(isalpha(exp[i - 1]) || isalnum(exp[i-1]))) // If it's not a number or character, go ahead and put a space.
				postfixExp.append(" .");
			else
				postfixExp.append(".");
		case ' ': break; // do nothing -- skip blank
		case '(': opStack.push(token);
			break;
		case ')': for (;;)
		{
			assert(!opStack.empty());
			topToken = opStack.top();
			opStack.pop();
			if (topToken == '(') break;
			postfixExp.append(BLANK + topToken);
		}
				  break;
		case '+': case '-': case '*': case '/': case '%': case '^':
			for (;;)
			{
				if (opStack.empty() || opStack.top() == '(' ||
					(token == '*' || token == '/' || token == '%') &&
					(opStack.top() == '+' || opStack.top() == '-') || token == '^')
				{
					opStack.push(token);
					break;
				}
				else
				{
					topToken = opStack.top();
					opStack.pop();
					postfixExp.append(BLANK + topToken);
				}
			}
			break;
		default: // operand
			if (postfixExp.size() != 0 && postfixExp[postfixExp.size() - 1] == '.') // Don't put a space if there is a . before. 
				postfixExp.append(EMPTY + token);
			else
				postfixExp.append(BLANK + token);
			for (;;)
			{
				if (!isalnum(exp[i + 1])) break; // end of indentifier
				i++;
				token = exp[i];
				postfixExp.append(1, token);
			}

		}

	}
	// Pop remaning
	for (;;)
	{
		if (opStack.empty()) break;
		topToken = opStack.top();
		opStack.pop();
		if (topToken != '(')
		{
			postfixExp.append(BLANK + topToken);
		}
		else
		{
			cout << " *** Error in infix expression ***\n";
			break;
		}
	}

	return postfixExp;
}

