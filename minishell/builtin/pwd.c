/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:22 by dham              #+#    #+#             */
/*   Updated: 2022/12/21 20:11:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int	ft_pwd(void)
{
	char	path_buf[PATH_MAX];

	getcwd(path_buf, PATH_MAX);
	printf("%s\n", path_buf);
	return (0);
}

int	exe_pwd(char **argv)
{
	
}