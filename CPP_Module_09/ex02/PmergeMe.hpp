/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:41:20 by dham              #+#    #+#             */
/*   Updated: 2023/03/26 01:15:27 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <sys/time.h>

#define CHANGE_SORT 8

class PmergeMe
{
public:
	PmergeMe(int n);
	~PmergeMe(void);

	int init_arr(char *argv[]);
	void vector_sort(void);
	void vector_insert(int start, int end);
	void vector_merge(int start, int end, std::vector<int> &res);
	void deque_sort(void);
	void deque_insert(int start, int end);
	void deque_merge(int start, int end, std::deque<int> &res);
	static bool valid_input(const char *str);
	static time_t diff_time(struct timeval t1, struct timeval t2);
private:
	int num_element;
	int *arr;
	std::vector<int> v;
	std::deque<int> d;

	PmergeMe(const PmergeMe &copy);
	PmergeMe	&operator=(const PmergeMe &copy);
};

#endif
