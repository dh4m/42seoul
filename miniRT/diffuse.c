/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:31:30 by dham              #+#    #+#             */
/*   Updated: 2023/03/04 23:13:08 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

t_color	diffuse_value(t_hitpoint *hitinfo, t_content *content, t_obj *hit_obj)
{
	t_color	ret_c;
	t_color	temp_c;
	t_vec	temp_v;
	t_light	*light;

	ret_c.r = 0;
	ret_c.g = 0;
	ret_c.b = 0;
	light = content->light_list.next;
	while(light)
	{
		if (light_hit(light, &hitinfo->hit_p, content, hit_obj))
		{
			temp_c = reflex_color(&light->color, &hitinfo->point_color);
			temp_v = vec_minus(&light->loc, &hitinfo->hit_p);
			vector_normalize(&temp_v);
			if (vec_inner(&hitinfo->nomal_v, &temp_v) > 0)
			{
				bright_set(&temp_c, vec_inner(&hitinfo->nomal_v, &temp_v) \
							* (1 - hit_obj->reflection) * attenuation(light, hitinfo));
				ret_c = color_combine(&ret_c, &temp_c);
			}
		}
		light = light->next;
	}
	return (ret_c);
}
