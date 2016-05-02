/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:49:33 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/02 16:55:18 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "get_next_line.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>
# define MAXREFLECTION 5
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define SPEED 30
# define LIGHT 0
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define CONE 4

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef struct	s_light
{
	t_vector	center;
	t_color		color;
}				t_light;

typedef struct	s_figure
{
	int			name;
	double		radius;
	t_vector	center;
	t_color		color;
	t_vector	angle;
	double		specular;
	double		specular_power;
	int			shiny;
}				t_figure;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bg_color;
	int			final_color;
	int			bpp;
	int			line;
	int			endian;
	int			keyup;
	int			keydown;
	int			keyleft;
	int			keyright;
	int			nbobj;
	int			nblight;
	double		t;
	double		w;
	double		h;
	double		xx;
	double		zz;
	double		angle;
	t_vector	inter;
	t_color		color;
	t_color		tmp_color;
	t_figure	*object;
	t_vector	cam_angle;
	t_vector	eye;
	t_light		*light;
	int			start_h;
	int			end_h;
	t_vector	tmp_l_center;
	t_vector	tmp_inter;
	t_vector	tmp_center;
	t_vector	tmp_rlight;
	t_vector	reflect;
	t_vector	orig_reflect;
	int			i2;
}				t_env;

void			*raytracer(void *arg);
t_vector		rotations(t_vector vec, double x, double y, double z);
/*
**	-------------------	INITIALISATION	---------------------------
*/
void			init_camera(t_env *rt);
void			init_all(char *file, t_env *rt);
void			count_light(t_env *rt, char *file);
/*
**	-------------------------------------------------------
*/
/*
**	--------------------	PARSER	---------------------------
*/
void			global_parser(char *file, t_env *rt);
void			count_objects(t_env *rt, char *file);
void			parsing_camera(int fd, t_env *rt);
void			parsing_objects(int fd, char *object, t_env *rt);
void			parsing_light(int fd, t_env *rt);
/*
**	-------------------------------------------------------
*/
/*
**	-------------------	EVENTS	---------------------------
*/
int				expose(t_env *rt);
int				key_press(int keycode, t_env *rt);
int				key_release(int keycode, t_env *rt);
/*
**	-------------------------------------------------------
*/
/*
**	-------------------	OBJECTS	---------------------------
*/
int				sphere(t_vector r, t_figure s, double *t, t_vector eye);
int				plane(t_vector r, t_figure p, double *t, t_vector eye);
int				cylinder(t_vector r, t_figure cy, double *t, t_vector eye);
int				cone(t_vector r, t_figure co, double *t, t_vector eye);
/*
**	-------------------------------------------------------
*/
/*
**	-------------------	LIGHT	---------------------------
*/
void			light(t_env *rt, t_figure object, t_light light, t_vector ray);
/*
**	-------------------------------------------------------
*/
/*
**	-------------------	VECTORS	---------------------------
*/
t_vector		vecsub(t_vector *v1, t_vector *v2);
double			vecdot(t_vector *v1, t_vector *v2);
t_vector		normalize(t_vector *v1);
t_vector		vecadd(t_vector *v1, t_vector *v2);
t_vector		vecscale(t_vector *v, double factor);
/*
**	-------------------------------------------------------
*/
/*
**	------------	OTHER	-----------------------
*/
void			ft_exit(char *s);
void			mlx_pixel_put_to_image(int color, t_env *img, int x, int y);
void			missing_parameter(char **tab);
void			check_color(double r, double g, double b);
t_vector		calcul_ptinter(t_vector eye, t_vector r, double t);
void			render(t_env *rt);
void			tab_free(char **tab);
/*
**	-------------------------------------------------------
*/

#endif
