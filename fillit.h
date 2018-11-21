/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 13:33:43 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 19:18:45 by aducimet    ###    #+. /#+    ###.fr     */
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

typedef struct		s_tetri
{
	struct s_tetri	*next;
	struct s_point	*list;
}					t_tetri;

t_point				new_point(int x, int y);
t_tetri				*new_tetri();
void				add_elem(t_tetri **alist, t_tetri *elem);

#endif
