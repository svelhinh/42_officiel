/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:56:17 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/11 14:07:37 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_init(int *nblines, int *error, int *gnlret, int *blk)
{
	*nblines = 0;
	*error = 0;
	*gnlret = 1;
	*blk = 0;
}