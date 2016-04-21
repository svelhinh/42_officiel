/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:08:22 by svelhinh          #+#    #+#             */
/*   Updated: 2016/04/20 15:08:24 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	put_color(t_rt *rt, int object, int i)
{
	if (object == 0)
		rt->color = rt->s[i].color.r * 255 * 0x10000 +
					rt->s[i].color.g * 255 * 0x100 +
					rt->s[i].color.b * 255;
	else if (object == 1)
		rt->color = rt->p[i].color.r * 255 * 0x10000 +
					rt->p[i].color.g * 255 * 0x100 +
					rt->p[i].color.b * 255;
	else if (object == 2)
		rt->color = rt->c[i].color.r * 255 * 0x10000 +
					rt->c[i].color.g * 255 * 0x100 +
					rt->c[i].color.b * 255;
	else
		rt->color = rt->background_color;
}

static void	intersection(t_rt *rt)
{
	int imax;
	int	i;
	int	i2;
	int	object;

	imax = (rt->nbs > rt->nbp) ? (rt->nbs) : (rt->nbp);
	imax = (rt->nbc > imax) ? (rt->nbc) : (imax);
	i = 0;
	object = -1;
	rt->t = 200000;
	while (i < imax)
	{
		if (i < rt->nbs && sphere(&rt->r, &rt->s[i], &rt->t))
		{
			object = 0;
			i2 = i;
		}
		if (i < rt->nbp && plane(&rt->r, &rt->p[i], &rt->t))
		{
			object = 1;
			i2 = i;
		}
		if (i < rt->nbc && cylinder(&rt->r, &rt->c[i], &rt->t))
		{
			object = 2;
			i2 = i;
		}
		i++;
	}
	put_color(rt, object, i2);
}

void		raytracer(t_rt *rt)
{
	int x;
	int y;

	y = 0;
	rt->r.start.x = rt->campos.x;
	rt->r.start.y = rt->campos.y;
	rt->r.start.z = rt->campos.z;
	rt->r.dir.z = -rt->w + rt->campos.z;
	while (y < rt->h)
	{
		x = 0;
		while (x < rt->w)
		{
			rt->r.dir.x = x - rt->w / 2 - rt->campos.x;
			rt->r.dir.y = y - rt->h / 2 - rt->campos.y;
			intersection(rt);
			mlx_pixel_put_to_image(rt->color, rt, x, y);
			x++;
		}
		y++;
	}
}