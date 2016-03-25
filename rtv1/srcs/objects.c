/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:43:50 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/25 12:38:41 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
 ** tab[0] = t0, tab[1] = t1
*/

int		sphere(t_ray *r, t_sphere *s, float *t)
{
	t_vector3d	dist;
	float		tab[2];
	float		b;
	float		d;
	int			retval;

	dist = vectorsub(&s->pos, &r->start, 0);
	b = vectordot(&r->dir, &dist, 0);
	d = pow(b, 2) - vectordot(&dist, &dist, 0) + pow(s->radius, 2);
	if (d < 0)
		return (0);
	tab[0] = b - sqrt(d);
	tab[1] = b + sqrt(d);
	retval = 0;
	if (tab[0] > 0.1 && tab[0] < *t)
	{
		*t = tab[0];
		retval = 1;
	}
	if (tab[1] > 0.1 && tab[1] < *t)
	{
		*t = tab[1];
		retval = 0;
	}
	return (retval);
}

/*
 ** e[0] = a, e[1] = b, e[2] = c
*/

int		plane(t_ray *r, t_plane *p, float *t)
{
	float	tmp;
	float	A;
	float	B;
	float	C;
	float	angle;

	angle = 0.3;
	A = p->norm.x;
	B = p->norm.x + cos(angle) * p->norm.y - sin(angle) * p->norm.z;
	C = p->norm.x + sin(angle) * p->norm.y + cos(angle) * p->norm.z;
	tmp = -(p->height + A * r->start.x + B * r->start.y + C * r->start.z) / (A * r->dir.x + B * r->dir.y + C * r->dir.z);
	if (tmp < *t && tmp > 0.01)
	{
		*t = tmp;
		return (1);
	}
	return (0);
}

/*
 ** tab[0] = t0, tab[1] = t1, tab[2] = xyz
*/

int		cylinder(t_ray *r, t_cylinder *cy, float *t)
{
	/*float	a;
	float	b;
	float	c;
	float	t0;
	float	t1;
	int		retval;
	float	discr;

	a = cy->pos.y * pow(r->dir.y, 2) + cy->pos.z * pow(r->dir.z, 2);
	b = cy->pos.y * 2 * r->start.y * r->dir.y + cy->pos.z * 2 * r->start.z * r->dir.z;
	c = cy->pos.y * pow(r->start.y, 2) + cy->pos.z * pow(r->start.z, 2) - pow(cy->radius, 2);
	discr = pow(b, 2) - 4 * a * c;
	if (discr < 0)
		return (0);
	t0 = (-b - sqrt(discr)) / (2 * a);
	t1 = (-b + sqrt(discr)) / (2 * a);
	retval = 0;
	if (t0 > 0.1 && t0 < *t)
	{
		*t = t0;
		retval = 1;
	}
	if (t1 > 0.1 && t1 < *t)
	{
		*t = t1;
		retval = 0;
	}
	return (retval);*/
	t_vector3d	dist;
	float		tab[3];
	float		b;
	float		d;
	int			retval;

	tab[2] = 0;
	if (cy->pos.x == 0)
		tab[2] = 1;
	else if (cy->pos.y == 0)
		tab[2] = 2;
	else if (cy->pos.z == 0)
		tab[2] = 3;
	dist = vectorsub(&cy->pos, &r->start, tab[2]);
	b = vectordot(&r->dir, &dist, tab[2]);
	d = pow(b, 2) - vectordot(&dist, &dist, tab[2]) + pow(cy->radius, 2);
	if (d < 0)
		return (0);
	tab[0] = b - sqrt(d);
	tab[1] = b + sqrt(d);
	retval = 0;
	if (tab[0] > 0.1 && tab[0] < *t)
	{
		*t = tab[0];
		retval = 1;
	}
	if (tab[1] > 0.1 && tab[1] < *t)
	{
		*t = tab[1];
		retval = 0;
	}
	return (retval);
}

int		cone(t_ray *r, t_cone *co, float *t)
{
	t_vector3d	dist;
	float		tab[2];
	float		b;
	float		d;
	int			retval;

	dist = vectorsub(&co->pos, &r->start, 0);
	b = vectordot(&r->dir, &dist, co->axis);
	d = pow(b, 2) - vectordot(&dist, &dist, co->axis) + pow(co->radius, 2);
	if (d < 0)
		return (0);
	tab[0] = b - sqrt(d);
	tab[1] = b + sqrt(d);
	retval = 0;
	if (tab[0] > 0.1 && tab[0] < *t)
	{
		*t = tab[0];
		retval = 1;
	}
	if (tab[1] > 0.1 && tab[1] < *t)
	{
		*t = tab[1];
		retval = 0;
	}
	return (retval);
}
