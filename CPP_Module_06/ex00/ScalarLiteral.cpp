/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarLiteral.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/02/12 15:02:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarLiteral.hpp"
#include <cstdlib>
#include <iostream>

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
		_actual_type.type_int = static_cast<int>(std::strtol(_raw.c_str(), NULL, 10));
		break ;
	case FLOAT:
		_actual_type.type_float = std::strtof(_raw.c_str(), NULL);
		break ;
	case DOUBLE:
		_actual_type.type_double = std::strtod(_raw.c_str(), NULL);
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
	char *end_ptr;
	long l;

	l = std::strtol(raw.c_str(), &end_ptr, 10);
	if (*end_ptr || (l == LONG_MAX && errno == ERANGE)
		|| (l == LONG_MIN && errno == ERANGE)
		|| (l > INT_MAX) || (l < INT_MIN))
		return (false);
	return (true);
}

bool ScalarLiteral::_isfloat(const std::string &raw)
{
	char *end_ptr;
	float f;

	f = std::strtof(raw.c_str(), &end_ptr);
	if (!(end_ptr[0] == 'f' && end_ptr[1] == '\0') 
		|| (f == HUGE_VALF && errno == ERANGE)
		|| (f == -HUGE_VALF && errno == ERANGE)
		|| (f == 0 && errno == ERANGE))
		return (false);
	return (true);
}

bool ScalarLiteral::_isdouble(const std::string &raw)
{
	char *end_ptr;
	double d;

	d = std::strtod(raw.c_str(), &end_ptr);
	if (*end_ptr)
		return (false);
	return (true);
}

int ScalarLiteral::_typeDecision(void)
{
	if (_isint(_raw))
		_type = INT;
	else if (_isfloat(_raw))
		_type = FLOAT;
	else if (_isdouble(_raw))
		_type = DOUBLE;
	else if (_raw.length() == 1)
		_type = CHAR;
	else
		_type = UNAVILABLE;
	return (_type);
}

void ScalarLiteral::printAllConversion(void)
{
	std::cout.setf(std::ios::showpoint);
	printCharType();
	printIntType();
	printFloatType();
	printDoubleType();
}

void ScalarLiteral::printCharType(void)
{
	std::cout << "char: ";
	switch (_type)
	{
	case CHAR:
		if (isprint(_actual_type.type_char))
			std::cout << '\'' << _actual_type.type_char << '\'';
		else
			std::cout << "Non displayable";
		break ;

	case INT:
		if (CHAR_MIN > _actual_type.type_int || _actual_type.type_int > CHAR_MAX)
			std::cout << "impossible";
		else if (!isprint(_actual_type.type_int))
			std::cout << "Non displayable";
		else
			std::cout << '\'' << static_cast<char>(_actual_type.type_int) << '\'';
		break ;

	case FLOAT:
		if (CHAR_MIN > _actual_type.type_float || _actual_type.type_float > CHAR_MAX
			|| isnan(_actual_type.type_float))
			std::cout << "impossible";
		else if (!isprint(static_cast<int>(_actual_type.type_float)))
			std::cout << "Non displayable";
		else
			std::cout << '\'' << static_cast<char>(_actual_type.type_float) << '\'';
		break ;

	case DOUBLE:
		if (CHAR_MIN > _actual_type.type_double || _actual_type.type_double > CHAR_MAX
			|| isnan(_actual_type.type_double))
			std::cout << "impossible";
		else if (!isprint(static_cast<int>(_actual_type.type_double)))
			std::cout << "Non displayable";
		else
			std::cout << '\'' << static_cast<char>(_actual_type.type_double) << '\'';
		break ;

	default:
		std::cout << "impossible";
		break ;
	}
	std::cout << std::endl;
}

void ScalarLiteral::printIntType(void)
{
	std::cout << "int: ";
	switch (_type)
	{
	case CHAR:
		std::cout << static_cast<int>(_actual_type.type_char);
		break ;

	case INT:
		std::cout << _actual_type.type_int;
		break ;

	case FLOAT:
		if (INT_MIN > _actual_type.type_float || _actual_type.type_float > INT_MAX
			|| isnan(_actual_type.type_float))
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(_actual_type.type_float);
		break ;

	case DOUBLE:
		if (INT_MIN > _actual_type.type_double || _actual_type.type_double > INT_MAX
			|| isnan(_actual_type.type_double))
			std::cout << "impossible";
		else
			std::cout << static_cast<int>(_actual_type.type_double);
		break ;

	default:
		std::cout << "impossible";
		break ;
	}
	std::cout << std::endl;
}

void ScalarLiteral::printFloatType(void)
{
	std::cout << "float: ";
	switch (_type)
	{
	case CHAR:
		std::cout << static_cast<float>(_actual_type.type_char) << 'f';
		break ;

	case INT:
		std::cout << static_cast<float>(_actual_type.type_int) << 'f';
		break ;

	case FLOAT:
		std::cout << _actual_type.type_float << 'f';
		break ;

	case DOUBLE:
		if (_actual_type.type_double > HUGE_VALF)
			std::cout << "inff";
		else if (_actual_type.type_double < -HUGE_VALF)
			std::cout << "-inff";
		else
			std::cout << static_cast<float>(_actual_type.type_double) << 'f';
		break ;

	default:
		std::cout << "impossible";
		break ;
	}
	std::cout << std::endl;
}

void ScalarLiteral::printDoubleType(void)
{
	std::cout << "double: ";
	switch (_type)
	{
	case CHAR:
		std::cout << static_cast<double>(_actual_type.type_char);
		break ;

	case INT:
		std::cout << static_cast<double>(_actual_type.type_int);
		break ;

	case FLOAT:
		std::cout <<  static_cast<double>(_actual_type.type_float);
		break ;

	case DOUBLE:
		if (_actual_type.type_double == HUGE_VAL)
			std::cout << "inf";
		else if (_actual_type.type_double == -HUGE_VAL)
			std::cout << "-inf";
		else
			std::cout << _actual_type.type_double;
		break ;

	default:
		std::cout << "impossible";
		break ;
	}
	std::cout << std::endl;
}
