/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:19:17 by svelhinh          #+#    #+#             */
/*   Updated: 2016/01/08 17:34:51 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# include <unistd.h>
# include "../lib/libft.h"

int					get_next_line(int const fd, char **line);
typedef struct		s_varg
{
	char			*buf;
	size_t			ret;
	size_t			len;
	size_t			start;
}					t_varg;

#endif
