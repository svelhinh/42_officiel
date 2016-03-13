/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:59:57 by svelhinh          #+#    #+#             */
/*   Updated: 2016/03/11 12:12:43 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	line2_free(char **line2)
{
	int i;

	i = 0;
	while (line2[i])
	{
		ft_strdel(line2);
		i++;
	}
	free(line2);
	line2 = NULL;
}