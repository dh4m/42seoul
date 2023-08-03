/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:21:13 by jinam             #+#    #+#             */
/*   Updated: 2023/03/14 12:26:52 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>

t_light	*get_last_light(t_light *head)
{
	t_light	*curr;

	curr = head;
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

int	parse_light(const char **str, t_light *light)
{
	t_light			*lst;
	const int		len = ft_array_len((char **)str);

	if (len != 4)
		return (UNAVILABLE_RT_FILE);
	lst = get_last_light(light);
	lst->next = ft_calloc(sizeof(t_light), 1);
	if (!lst->next)
		return (FATAL_ERROR);
	if (init_point((char *)str[1], &lst->next->loc) == UNAVILABLE_RT_FILE)
		return (UNAVILABLE_RT_FILE);
	lst->next->bright = ft_atof(str[2]);
	if (lst->next->bright < 0 || lst->next->bright > 100000)
		return (UNAVILABLE_RT_FILE);
	if (init_color((char *)str[3], &lst->next->color) == UNAVILABLE_RT_FILE)
		return (UNAVILABLE_RT_FILE);
	return (SUCCESS);
}
