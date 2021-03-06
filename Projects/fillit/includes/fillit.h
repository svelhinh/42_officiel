/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:58:00 by svelhinh          #+#    #+#             */
/*   Updated: 2015/12/31 12:44:53 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <fcntl.h>
# include "../lib/libft.h"
# include "get_next_line.h"

typedef struct		s_varf
{
	int				nblines;
	int				error;
	int				gnlret;
	int				blk;
	char			*line;
	char			*coord;
	char			*file;
	int				i;
	int				blkx;
	int				x;
	int				blky;
	int				y;
	char			**tab;
	int				fd;
	int				contact;
	int				ret;
}					t_varf;

typedef struct		s_coord
{
	int				x[4];
	int				y[4];
	char			c;
	struct s_coord	*next;

}					t_coord;

void				ft_errors(int fd, char **file);
void				ft_init(int *nblines, int *error, int *gnlret);
char				*ft_letters(char *file);
t_coord				**ft_store(char *file);
t_coord				*ft_move(t_coord *first, int x, int y);
char				**ft_tab_store(char **tab, t_coord *coord, int tablen);
char				**ft_empty(char **tab, int tablen);
int					ft_check(char **tab, t_coord *coord, int tablen);
char				**ft_result(t_coord *coord, int tablen);
void				ft_exit(void);
void				ft_check_tetri(int fd);
void				ft_contact(t_varf v);

#endif
