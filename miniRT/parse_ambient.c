/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:10:57 by jinam             #+#    #+#             */
/*   Updated: 2023/03/14 12:26:55 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minirt.h"
#include <stdio.h>

int	_error_exit(char **tmp)
{
	ft_split_free(tmp);
	return (UNAVILABLE_RT_FILE);
}

int	parse_ambient(const char **str, t_ambient *ambient)
{
	const int	len = ft_array_len((char **)str);

	if (len != 3 || ambient->active == PARSING_SUCCESS)
		return (UNAVILABLE_RT_FILE);
	ambient->active = PARSING_SUCCESS;
	ambient->bright = ft_atof(str[1]);
	if (ambient->bright < 0 || ambient->bright > 100000)
		return (UNAVILABLE_RT_FILE);
	return (init_color((char *)str[2], &ambient->color));
}
