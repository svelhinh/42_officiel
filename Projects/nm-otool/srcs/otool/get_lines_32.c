/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines_32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:00:06 by svelhinh          #+#    #+#             */
/*   Updated: 2017/08/09 16:47:20 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

t_line		*get_lines(t_sec *text_sect, char *file_ptr)
{
	t_line		*lines;
	t_line		*current;
	uint32_t	addr;
	char		*file_off;
	char		*sect_end;

	addr = text_sect->addr;
	file_off = file_ptr + text_sect->offset;
	sect_end = file_off + text_sect->size;
	if (!text_sect->size || !(lines = (t_line *)ft_memalloc(sizeof(t_line))))
		return (NULL);
	current = lines;
	while (file_off < sect_end)
	{
		current->addr = ft_value_format(ft_value_to_hex(addr), 15, 8);
		current->hex = get_hex(file_off, sect_end, 0, 32);
		file_off += 16;
		addr += 16;
		if (file_off < sect_end)
			current->next = (t_line *)ft_memalloc(sizeof(t_line));
		else
			current->next = NULL;
		current = current->next;
	}
	return (lines);
}
