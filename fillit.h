/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 13:33:43 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 15:52:28 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

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

int					get_coord(char **tab, t_point **list);
t_point				get_abs_coord(char **tab);
t_point				new_point(int x, int y);
t_tetri				*new_tetri();
void				add_elem(t_tetri **alist, t_tetri *elem);
int					rccar(int nb);
int					ft_list_len(t_tetri	*list);
int					add_tetri(char ***atab, t_tetri **afirst);
char				**create_map(int size);
int					resolve(char **map, int map_size, t_tetri **afirst,
					char letter);
int					try_place_tetri(char **map, int map_size, t_tetri *list,
					t_point test);
int					place_tetri(char **map, t_tetri *list, t_point test,
					char letter);
int					delete_tetri(char **map, t_tetri *list, t_point test);
int					ft_fill_tab(char ***tab, int fd);
int					ft_first_read(int fd1);

void				ft_listdel(t_tetri **list);

#endif
