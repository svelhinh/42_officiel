/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 14:53:35 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/19 19:12:36 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check(t_coord *coord, int tablen, char **tab)
{
	int blk;
	t_varf v;

	blk = 0;
	v.x = 0;
	v.y = 0;
	while (!ft_check_tab(tab, &coord, tablen) && v.y < tablen)
	{
		if (v.x == tablen)
		{
			v.x = 0;
			v.y++;
		}
		coord = ft_move(&coord, v.x, v.y);
		v.x++;
	}
	if (v.y == tablen)
		return (0);
	return (1);
}

char	**ft_backtracking(t_coord *coord, int tablen, char **tab)
{
	if (ft_check(coord, tablen, tab))
	{
		tab = ft_tab_store(tab, coord, tablen);
		coord = coord->next;
		ft_backtracking(coord, tablen, tab);
		return (tab);
	}
	return (NULL);
}

char	**ft_resize_tab(t_coord *first)
{
	char **tab;
	int tablen;
	t_varf v;

	tablen = 2;
	tab = NULL;
	v.x = 0;
	v.y = 0;
	tab = ft_empty(tab, tablen);
	first = ft_move(&first, v.x, v.y);
	while (!ft_check(first, tablen, tab))
	{
		tablen++;
		tab = ft_empty(tab, tablen);
	}
	return (tab);
}
