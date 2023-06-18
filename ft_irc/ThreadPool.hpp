/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThreadPool.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:38:41 by dham              #+#    #+#             */
/*   Updated: 2023/05/02 16:24:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef THREADPOOL_HPP
# define THREADPOOL_HPP

# define THREAD_NUM 16

class ThreadPool
{
public:
	ThreadPool(void);
	~ThreadPool(void);

	int init(void);
	//int 
private:

	ThreadPool(const ThreadPool &copy);
	ThreadPool	&operator=(const ThreadPool &copy);
};

#endif
