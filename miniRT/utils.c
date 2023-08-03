/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:25:22 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:50:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	invalid_args(void)
{
	ft_putstr_fd("invalid argument!!\n", 1);
	exit(1);
}

int	error_msg(int code, t_content *content)
{
	clear_list(content);
	if (code == FATAL_ERROR)
		ft_putstr_fd("Parsing Error\n", 2);
	else if (code == RT_FILE_OPEN_ERROR)
		ft_putstr_fd("RT file open Error\n", 2);
	else if (code == UNAVILABLE_RT_FILE)
		ft_putstr_fd("Unavailable RT file Error\n", 2);
	return (code);
}

int	clear_list(t_content *content)
{
	t_light	*light;
	t_obj	*obj;
	void	*temp;

	light = content->light_list.next;
	while (light)
	{
		temp = light;
		light = light->next;
		free(temp);
	}
	obj = content->obj_list.next;
	while (obj)
	{
		texture_free(obj->texture);
		texture_free(obj->bump);
		temp = obj;
		obj = obj->next;
		free(temp);
	}
	return (SUCCESS);
}
