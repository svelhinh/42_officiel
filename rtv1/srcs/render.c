/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:21:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/15 11:47:16 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		draw(t_rt *rt, char *object, int x, int y)
{
	if (rt->currentobj != -1)
	{
		if (!ft_strcmp("sphere", object))
			mlx_pixel_put_to_image(rt->s[rt->currentobj].color, rt, x, y);
		else if (!ft_strcmp("plane", object))
			mlx_pixel_put_to_image(rt->p[rt->currentobj].color, rt, x, y);
		else if (!ft_strcmp("cylinder", object))
			mlx_pixel_put_to_image(rt->c[rt->currentobj].color, rt, x, y);
		else if (!ft_strcmp("cone", object))
			mlx_pixel_put_to_image(rt->co[rt->currentobj].color, rt, x, y);
	}
	else
		mlx_pixel_put_to_image(rt->default_color, rt, x, y);
}

void			render(t_rt *rt)
{
	char		*object;
	float		x;
	float		y;
	float		z;
	float		coeff;
	int			level;
	//t_vector3d	scaled;
	//t_vector3d	newstart;

	rt->materials[0].diffuse.red = 1;
	rt->materials[0].diffuse.green = 0;
	rt->materials[0].diffuse.blue = 0;
	rt->lights[0].pos.x = 0;
	rt->lights[0].pos.y = 0;
	rt->lights[0].pos.z = 0;
	rt->lights[0].intensity.red = 1;
	rt->lights[0].intensity.green = 1;
	rt->lights[0].intensity.blue = 1;
	z = rt->campos.z;
	y = 0;
	while (y < SH)
	{
		x = 0;
		while (x < SW)
		{
			coeff = 1;
			level = 0;
			rt->r.start.x = x + rt->campos.x;
			rt->r.start.y = y + rt->campos.y;
			rt->r.start.z = z;
			while (coeff > 0 && level < 15)
			{
				object = NULL;
				object = intersect(rt, &rt->currentobj, object);
				coeff = 0;
			}
			draw(rt, object, x, y);
			ft_strdel(&object);
			x++;
		}
		y++;
	}
}
