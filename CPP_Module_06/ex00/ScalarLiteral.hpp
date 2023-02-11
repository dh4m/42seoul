/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarLiteral.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:44:21 by dham              #+#    #+#             */
/*   Updated: 2023/02/11 20:10:32 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARLITERAL_HPP
# define SCALARLITERAL_HPP

#include <string>

enum literal_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNAVILABLE
};

union ActualType
{
	char type_char;
	int type_int;
	float type_float;
	double type_double;
};

class ScalarLiteral
{
public:
	ScalarLiteral(const std::string &raw);
	ScalarLiteral(const ScalarLiteral &copy);
	~ScalarLiteral(void);

	ScalarLiteral	&operator=(const ScalarLiteral &copy);

	void printAllConversion(void);
	void printCharType(void);
	void printIntType(void);
	void printFloatType(void);
	void printDoubleType(void);
private:
	int _typeDecision(void);
	std::string _raw;
	int _type;
	ActualType _actual_type;

	ScalarLiteral(void);
};

#endif
