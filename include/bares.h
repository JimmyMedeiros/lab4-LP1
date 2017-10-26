/**
 * @file     bares.h
 * @brief    Implementação dos algorítmos Bares.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    26/10/2017
 * @date     26/10/2017
 *
 */

#ifndef _BARES_H_
#define _BARES_H_ 

#include <iostream>  // cout, endl 
#include <stack>     // stack 
#include <string>    // string 
#include <cassert>   // assert 
#include <cmath>     // pow 
#include <stdexcept> // std::runtime_error

using value_type = long int;
using symbol = char;

/**
 * @brief	Verfifica se o símbolo é um dígito
 */
bool is_operand( symbol s ) 
{
	return s >= '0' and s <= '9' ;
}

bool is_operator( symbol c ) 
{
	return std::string("+-*/%%^").find( c ) != std::string::npos;
}

value_type char2integer( symbol ch ) 
{
	return ch - '0';
}

value_type execute_operator( value_type term1, value_type term2, symbol op) 
{
	value_type result;
	switch( op )
	{
		case '+':
			result = term1 + term2; break;
		case '-':
			result = term1 - term2; break;
		case '*':
			result = term1 * term2; break;
		case '^':
			result = pow( term1, term2 ); break;
		case '/':
			if ( term2 == 0 ) throw std::runtime_error(" Division by zero " );
			result = term1 / term2; break;
		case '%':
			if ( term2 == 0 ) throw std::runtime_error(" Division by zero " );
			result = term1 % term2; break;
		}
	return result;
}

/**
 * @brief	Uma função que calcula o resultado de uma expressão posfixa.
 * @param	postfix A expressão posfixa que será calculada
 * @return	Um value_type (long int) com o resultado da expressão.
 */
value_type evaluate_postfix( std::string postfix ) 
{
// Stack of numbers.
	std::stack< value_type > st;
// Process each symbol in the postfix experssion.
	for (auto i = 0u; i < postfix.size(); ++i)
	{
		if ( is_operand( postfix[i] ) )
		{
			value_type temp = 0;
			
			while ( is_operand( postfix[i] ) ) 
			{
				temp = 10*temp + char2integer( postfix[i] );
				++i;
			}
			--i;
			st.push( temp );
		}
		else if ( is_operator( postfix[i] ) )
		{
			// Pops out the two terms of the binary operation...
			auto term2 = st.top();
			st.pop(); 
			// Invert the order first!
			auto term1 = st.top();
			st.pop();
			// ... executes the operation, and...
			auto r = execute_operator( term1, term2, postfix[i] );
			// ... pushes the result back onto the stack.
			st.push( r );
		}
	}
	// If everything goes smoothly, the result should be on the top of the stack.
	return st.top(); 
}

#endif