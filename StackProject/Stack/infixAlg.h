/***********************************************************************
* Header:
*    Infix
* Summary:
*    This class contains the definition for a function that uses the stack
*    class to convert an infix expression into a post fix expression.
*
* Author
*    Matthew Brown
************************************************************************/

#pragma once
#ifndef INFIXALG_H
#define INFIXALG_H

#include <string>

using namespace std;

class InfixAlg
{

private:
	string exp;

public:
	InfixAlg() { exp = ""; }
	InfixAlg(string in) { exp = in; }
	~InfixAlg();
	string to_postFix();
};

#endif
