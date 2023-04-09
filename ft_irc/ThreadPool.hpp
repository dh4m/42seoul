/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThreadPool.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:38:41 by dham              #+#    #+#             */
/*   Updated: 2023/04/09 14:39:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef THREADPOOL_HPP
# define THREADPOOL_HPP

class ThreadPool
{
public:
	ThreadPool(void);
	
	~ThreadPool(void);

	
private:

	ThreadPool(const ThreadPool &copy);
	ThreadPool	&operator=(const ThreadPool &copy);
};

#endif
