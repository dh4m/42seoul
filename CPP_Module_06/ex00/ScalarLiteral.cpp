/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarLiteral.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 20:21:04 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarLiteral.hpp"

ScalarLiteral::ScalarLiteral(const std::string &raw)
: _raw(raw)
{
	_type = _typeDecision();
	switch (_type)
	{
	case CHAR:
		_actual_type.type_char = _raw[0];
		break ;
	case INT:
		_actual_type.type_int = std::stoi(_raw);
		break ;
	case FLOAT:
		_actual_type.type_float = std::stof(_raw);
		break ;
	case DOUBLE:
		_actual_type.type_double = std::stod(_raw);
		break ;
	default:
		_actual_type.type_double = 0;
		break ;
	}
}

ScalarLiteral::ScalarLiteral(const ScalarLiteral &copy)
: _raw(copy._raw), _type(copy._type), _actual_type(copy._actual_type)
{}

ScalarLiteral::~ScalarLiteral(void)
{}

ScalarLiteral	&ScalarLiteral::operator=(const ScalarLiteral &copy)
{
	_raw = copy._raw;
	_type = copy._type;
	_actual_type = copy._actual_type;
	return (*this);
}

int ScalarLiteral::_typeDecision(void)
{

}

void ScalarLiteral::printAllConversion(void)
{
	printCharType();
	printIntType();
	printFloatType();
	printDoubleType();
}

void ScalarLiteral::printCharType(void)
{
	
}

void ScalarLiteral::printIntType(void)
{

}

void ScalarLiteral::printFloatType(void)
{

}

void ScalarLiteral::printDoubleType(void)
{

}
