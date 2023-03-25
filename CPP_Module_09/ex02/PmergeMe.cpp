/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:41:26 by dham              #+#    #+#             */
/*   Updated: 2023/03/26 01:31:45 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe(int n)
{
	arr = new int[n];
	num_element = n;
}

PmergeMe::~PmergeMe(void)
{
	delete[] arr;
}

int PmergeMe::init_arr(char *argv[])
{
	int i = 1;

	while (argv[i])
	{
		if (!valid_input(argv[i]))
			return (0);
		arr[i - 1] = std::atoi(argv[i]);
		i++;
	}
	i = 0;
	std::cout << "Before: ";
	while (i < num_element)
	{
		std::cout << arr[i] << ' ';
		i++;
	}
	std::cout << std::endl;
	return (1);
}

void PmergeMe::vector_sort(void)
{
	struct timeval begin, end;
	std::vector<int> temp;

	gettimeofday(&begin, NULL);
	for (int i = 0; i < num_element; i++)
		v.push_back(arr[i]);
	temp.reserve(num_element);
	vector_merge(0, num_element - 1, temp);
	gettimeofday(&end, NULL);
	std::cout << "After: ";
	for (std::vector<int>::iterator it = v.begin();
		it != v.end();
		++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << num_element << " elements with std::vector : " \
			<< diff_time(begin, end) << " us" << std::endl;
}

void PmergeMe::vector_merge(int start, int end, std::vector<int> &res)
{

	if (end - start <= CHANGE_SORT)
	{
		vector_insert(start, end);
		return ;
	}

	int mid = start + (end - start) / 2;

	vector_merge(start, mid - 1, res);
	vector_merge(mid, end, res);

	int idx1 = start;
	int idx2 = mid;
	int res_idx = start;
	while (idx1 != mid || idx2 != end + 1)
	{
		if (idx1 == mid)
		{
			res[res_idx++] = v[idx2++];
		}
		else if (idx2 == end + 1)
		{
			res[res_idx++] = v[idx1++];
		}
		else
		{
			if (v[idx1] > v[idx2])
				res[res_idx++] = v[idx2++];
			else
				res[res_idx++] = v[idx1++];
		}
	}
	for (int i = start; i <= end; i++)
	{
		v[i] = res[i];
	}
}

void PmergeMe::vector_insert(int start, int end)
{
	int temp;
	int i, j;

	for (i = start + 1; i <= end; i++)
	{
		if (v[i - 1] < v[i])
			continue;
		temp = v[i];
		for (j = i; j > start && v[j - 1] >= temp; j--)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}

void PmergeMe::deque_sort(void)
{
	struct timeval begin, end;
	std::deque<int> temp;

	gettimeofday(&begin, NULL);
	for (int i = 0; i < num_element; i++)
		d.push_back(arr[i]);
	temp.resize(num_element);
	deque_merge(0, num_element - 1, temp);
	gettimeofday(&end, NULL);
	std::cout << "Time to process a range of " << num_element << " elements with std::deque : " \
			<< diff_time(begin, end) << " us" << std::endl;
}

void PmergeMe::deque_merge(int start, int end, std::deque<int> &res)
{
	if (end - start <= CHANGE_SORT)
	{
		deque_insert(start, end);
		return ;
	}
	int mid = start + (end - start) / 2;

	deque_merge(start, mid - 1, res);
	deque_merge(mid, end, res);

	int idx1 = start;
	int idx2 = mid;
	int res_idx = start;
	while (idx1 != mid || idx2 != end + 1)
	{
		if (idx1 == mid)
		{
			res[res_idx++] = v[idx2++];
		}
		else if (idx2 == end + 1)
		{
			res[res_idx++] = v[idx1++];
		}
		else
		{
			if (v[idx1] > v[idx2])
				res[res_idx++] = v[idx2++];
			else
				res[res_idx++] = v[idx1++];
		}
	}
	for (int i = start; i <= end; i++)
	{
		v[i] = res[i];
	}
}

void PmergeMe::deque_insert(int start, int end)
{
	int temp;
	int i, j;

	for (i = start + 1; i <= end; i++)
	{
		if (d[i - 1] < d[i])
			continue;
		temp = d[i];
		for (j = i; j > start && d[j - 1] >= temp; j--)
			d[j] = d[j - 1];
		d[j] = temp;
	}
}

bool PmergeMe::valid_input(const char *str)
{
	int i = 0;

	if (!str[0])
		return (false);
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

time_t PmergeMe::diff_time(struct timeval start, struct timeval end)
{
	long diff_sec;
	long diff_micro;

	diff_sec = end.tv_sec - start.tv_sec;
	diff_micro = end.tv_usec - start.tv_usec;
	return (diff_sec * 1000000 + diff_micro);
}