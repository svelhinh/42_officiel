/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:47 by svelhinh          #+#    #+#             */
/*   Updated: 2016/02/18 17:02:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../gnl/get_next_line.h"
# define ROT 0.09
# define MOVE 0.3
# define CSKY 0x7FD1EF
# define CFLOOR 0xaaaaaa
# define CFRONT 0x000051
# define CBACK 0x000073
# define CRIGHT 0x001095
# define CLEFT 0x023097
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define DOWN 125
# define UP 126
# define RIGHT 124
# define LEFT 123
# define ENTER 36
# define ZERO 29
# define ONE 18
# define TWO 19
# define THREE 20
# define ZERO2 82
# define ONE2 83
# define TWO2 84
# define THREE2 85
# define R 15
# define P 35
# define M 46

typedef struct	s_coords
{
	double		x;
	double		ymin;
	double		ymax;
	double		dx;
	double		dy;
	double		m;
	int			color;
}				t_coords;
typedef struct	s_ray
{
	int			sw;
	int			sh;
	int			mapx;
	int			mapy;
	int			x;
	int			stepx;
	int			stepy;
	int			hit;
	int			wall;
	int			wall_height;
	int			ymin;
	int			ymax;
	int			**map;
	int			i;
	int			size_line;
	int			bpp;
	int			endian;
	int			texx;
	int			texy;
	int			**texture;
	int			w;
	int			h;
	int			r;
	int			g;
	int			b;
	int			ftexx;
	int			ftexy;
	int			forward;
	int			back;
	int			leftrot;
	int			rightrot;
	int			nb_lvl;
	int			p;
	int			v;
	int			m;
	char		*img;
	char		*lvl;
	char		*data;
	void		*mlx;
	void		*win;
	void		*mini_map;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		walldistx;
	double		walldisty;
	double		walldistx2;
	double		walldisty2;
	double		wall_length;
	double		wallx;
	double		fwallx;
	double		fwally;
	double		distwall;
	double		distplayer;
	double		cdist;
	double		weight;
	double		cfloorx;
	double		cfloory;
	double		time;
	double		time_s;
	double		time_d;
}				t_ray;
int				key_press(int keycode, t_ray *r);
int				key_release(int keycode, t_ray *r);
int				expose(t_ray *r);
void			ft_swap(double *a, double *b);
void			ft_exit(char *s);
int				**parser(char *lvl);
void			raycasting(t_ray *r);
void			init_var(t_ray *r);
void			put_line(t_ray r);
void			load_tex(t_ray *r);
void			move_forward(t_ray *r);
void			move_back(t_ray *r);
void			rotate_left(t_ray *r);
void			rotate_right(t_ray *r);
int				check_lvl(char *lvl);
void			ft_win(t_ray *r);
void			principal_menu(t_ray *m, int i);
void			main2(t_ray r);
void			play(t_ray *m);
void			options(t_ray *m);
void			commands(t_ray *m);
void			resolution(t_ray *m);
void			ft_empty(t_ray *m, int i);
void			ft_pause(t_ray *p);
void			victory(int keycode, t_ray *r);
void			event_pause(int keycode, t_ray *r);
void			ft_floor(t_ray *r, t_coords *c);
void			ft_sky(t_ray *r, t_coords *c);
void			event_pause2(t_ray *r);
#endif
