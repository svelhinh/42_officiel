/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:48:40 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/17 17:42:28 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		calcul_light(t_env *rt, int i2, t_vector ray)
{
	int			i;

	i = 0;
	rt->color.r = 0;
	rt->color.g = 0;
	rt->color.b = 0;
	while (i < rt->nblight)
	{
		light(rt, rt->object[i2], rt->light[i], ray);
		i++;
	}
	rt->color.r /= rt->nblight;
	rt->color.g /= rt->nblight;
	rt->color.b /= rt->nblight;
	rt->color.r = (rt->color.r > 0xff) ? (0xff) : (rt->color.r);
	rt->color.g = (rt->color.g > 0xff) ? (0xff) : (rt->color.g);
	rt->color.b = (rt->color.b > 0xff) ? (0xff) : (rt->color.b);
}

void	intersection(t_env *rt, t_vector ray, t_vector origin)
{
	int			i;
	t_vector 	tmp_reflect;
	t_vector	n;

	rt->i2 = -1;
	i = 0;
	rt->t = 200000;
	rt->disk = 0;
	while (i < rt->nbobj)
	{
		if ((rt->object[i].name == SPHERE && sphere(ray, rt->object[i], &rt->t,
				origin)) ||
			(rt->object[i].name == PLANE && plane(ray, rt->object[i], &rt->t,
				origin)) ||
			(rt->object[i].name == CYLINDER && cylinder(ray, rt->object[i],
				&rt->t, origin)) ||
			(rt->object[i].name == CONE && cone(ray, rt->object[i], &rt->t,
				origin)) ||
			(rt->object[i].name == L_SPHERE && limited_sphere(ray, rt->object[i], &rt->t,
				origin, &rt->disk, 0)) ||
			(rt->object[i].name == L_CYLINDER && limited_cylinder(ray, rt->object[i], &rt->t,
				origin, &rt->disk, 0)))
			rt->i2 = i;
		i++;
	}
}

static void		scan(int pas, t_env *rt)
{
	int			x;
	int			y;
	t_vector	ray;

	y = rt->start_h;
	while (y < rt->end_h)
	{
		x = 0;
		while (x < rt->w)
		{
			ray.x = x - rt->w / 2 - rt->eye.x + rt->xx;
			ray.y = y - rt->h / 2 - rt->eye.y;
			ray.z = rt->w - rt->eye.z + rt->zz;
			ray = rotations(ray, rt->cam_angle.x, rt->cam_angle.y,
				rt->cam_angle.z);
			ray = normalize(&ray);
			intersection(rt, ray, rt->eye);
			rt->color2.r = rt->bg_color.r;
			rt->color2.g = rt->bg_color.g;
			rt->color2.b = rt->bg_color.b;
			if (rt->i2 != -1)
			{
				rt->inter = calcul_ptinter(rt->eye, ray, rt->t);
				calcul_light(rt, rt->i2, ray);
				rt->color2 = rt->color;
				reflec_refrac(rt, ray, rt->eye);
			}
			rt->final_color = (int)rt->color2.r * 0x10000 + (int)rt->color2.g * 0x100
				+ (int)rt->color2.b;
			mlx_pixel_put_to_image(rt->final_color, rt, x, y);
			x += pas;
		}
		y += pas;
	}
}

void			*raytracer(void *arg)
{
	int		pas;
	t_env	*rt;

	rt = (t_env *)arg;
	pas = 1;
	if (rt->keyup == 1 || rt->keydown == 1 || rt->keyleft == 1
		|| rt->keyright == 1)
		pas = rt->w / 640 + rt->h / 480;
	scan(pas, rt);
	pthread_exit(0);
}
