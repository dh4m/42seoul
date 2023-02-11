/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarLiteral.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 22:22:48 by dham             ###   ########.fr       */
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

bool ScalarLiteral::_isint(const std::string &raw)
{
	int idx = 0;
	int len = _raw.length();
	
	if ((raw[idx] == '+' || raw[idx] == '-') && raw.length() != 1)
		idx++;
	while (idx < len)
	{
		if (!('0' <= raw[idx] && raw[idx] <= '9'))
			return (false);
		idx++;
	}
	try
	{
		std::stoi(raw);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

bool ScalarLiteral::_isfloat(const std::string &raw)
{
	try
	{
		std::stof(raw);
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

bool ScalarLiteral::_isdouble(const std::string &raw)
{
	try
	{
		std::stod(raw);
		return (true);
	}
	catch(const std::out_of_range& e)
	{
		return (true);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
}

int ScalarLiteral::_typeDecision(void)
{
	if (_isint(_raw))
		_type = INT;
	else if (_isdouble(_raw))
		_type = DOUBLE;
	else if (_isfloat(_raw))//////////
		_type = FLOAT;
	else if (_raw.length() == 1 && isprint(_raw[0]))
		_type = CHAR;
	else
		_type = UNAVILABLE;
	
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
