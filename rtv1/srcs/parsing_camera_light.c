/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:12:20 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/24 18:25:58 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parsing_camera(int fd, t_rt *rt)
{
	char *line;
	char **line2;

	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			break ;
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "x_pos"))
			rt->campos.x = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "y_pos"))
			rt->campos.y = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "z_pos"))
			rt->campos.z = ft_atof(line2[2]);
		line2_free(line2);
		ft_strdel(&line);
	}
}

void	parsing_light(int fd, t_rt *rt)
{
	char		*line;
	char		**line2;

	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			break ;
		line2 = ft_strsplit(line, ' ');
		if (!ft_strcmp(line2[0], "x_pos"))
			rt->light.pos.x = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "y_pos"))
			rt->light.pos.y = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "z_pos"))
			rt->light.pos.z = ft_atof(line2[2]);
		else if (!ft_strcmp(line2[0], "color"))
		{
			rt->light.intensity.red = ft_atof(line2[2]);
			rt->light.intensity.green = ft_atof(line2[3]);
			rt->light.intensity.blue = ft_atof(line2[4]);
		}
		line2_free(line2);
		ft_strdel(&line);
	}
}
