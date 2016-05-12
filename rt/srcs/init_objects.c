/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:28:12 by svelhinh          #+#    #+#             */
/*   Updated: 2016/05/12 18:24:33 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_objects(t_env *rt)
{
	int i;

	i = 0;
	while (i < rt->nbobj)
	{
		rt->object[i].name = SPHERE;
		rt->object[i].radius = 30;
		rt->object[i].center.x = 0;
		rt->object[i].center.y = 0;
		rt->object[i].center.z = 0;
		rt->object[i].color.r = 0;
		rt->object[i].color.g = 0;
		rt->object[i].color.b = 0;
		rt->object[i].angle.x = 0;
		rt->object[i].angle.y = 0;
		rt->object[i].angle.z = 0;
		rt->object[i].separation = 0;
		rt->object[i].material.specular = 0;
		rt->object[i].material.specular_power = 0;
		rt->object[i].material.shiny = 0;
		rt->object[i].material.reflection = 0;
		i++;
	}
}

void		count_objects(t_env *rt, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_exit("\033[31mThis scene doesn't exist\n");
	while (get_next_line(fd, &line) > 0)
	{
		rt->nbobj += (!ft_strcmp(line, "object : sphere") ||
					!ft_strcmp(line, "object : plane") ||
					!ft_strcmp(line, "object : cylinder") ||
					!ft_strcmp(line, "object : cone") ||
					!ft_strcmp(line, "object : half_sphere") ||
					!ft_strcmp(line, "object : disk")) ? (1) : (0);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	(close(fd) == -1) ? (ft_exit("\033[31mThis scene failed to close")) : (0);
	if (!(rt->object = (t_figure *)malloc(sizeof(t_figure) * rt->nbobj)))
		ft_exit("malloc of rt->object failed in count_objects");
	// ft_putendl("1");
	init_objects(rt);
	// ft_putendl("2");
}
