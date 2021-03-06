/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_little_endian.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:35:13 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/23 18:39:13 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_little_endian(void)
{
	t_e	e;

	e.i = 0x01000000;
	return (!e.c[0]);
}
