/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 13:33:43 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 16:25:15 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_util
{
	int				count;
	int				max_hash;
}					t_util;

typedef struct		s_tetri
{
	struct s_tetri	*next;
	struct s_point	*list;
}					t_tetri;

void				ft_listdel(t_tetri **list);
void				add_elem(t_tetri **alist, t_tetri *elem);

char				**create_map(int size);

int					rccar(int nb);
int					ft_first_read(int fd1);
int					ft_list_len(t_tetri *list);
int					ft_fill_tab(char ***tab, int fd);
int					get_coord(char **tab, t_point **list);
int					add_tetri(char ***atab, t_tetri **afirst);
int					delete_tetri(char **map, t_tetri *list, t_point test);
int					resolve(char **map, int map_size, t_tetri **afirst,
					char letter);
int					place_tetri(char **map, t_tetri *list, t_point test,
					char letter);
int					try_place_tetri(char **map, int map_size, t_tetri *list,
					t_point test);

t_tetri				*new_tetri(void);
t_point				new_point(int x, int y);
#endif
