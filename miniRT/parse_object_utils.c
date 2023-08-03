/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:15:31 by jinam             #+#    #+#             */
/*   Updated: 2023/03/18 20:05:46 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include "libft/libft.h"

t_obj	*get_last_obj(t_obj *obj)
{
	t_obj	*curr;

	curr = obj;
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

int	init_nomal_vector(char *str, t_vec *v)
{
	char	**tmp;

	tmp = ft_split(str, ',');
	if (ft_array_len(tmp) != 3)
	{
		ft_split_free(tmp);
		return (UNAVILABLE_RT_FILE);
	}
	v->x = ft_atof(tmp[0]);
	v->y = ft_atof(tmp[1]);
	v->z = ft_atof(tmp[2]);
	ft_split_free(tmp);
	if (v->x < -1 || v->x > 1)
		return (UNAVILABLE_RT_FILE);
	if (v->y < -1 || v->y > 1)
		return (UNAVILABLE_RT_FILE);
	if (v->z < -1 || v->z > 1)
		return (UNAVILABLE_RT_FILE);
	return (SUCCESS);
}
