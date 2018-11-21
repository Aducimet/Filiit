/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 18:28:53 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 20:51:29 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fillit.h"
#include <stdio.h>

t_point	new_point(int x, int y)          // pour assigner des points 
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_tetri	*new_tetri()
{
	t_tetri	*tetri;

	tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	tetri->next = NULL;
	tetri->list = NULL;
	return (tetri);
}

void	add_elem(t_tetri **alist, t_tetri *elem)
{
	t_tetri *tmp;

	if (*alist == NULL)
		*alist = elem;
	else
	{
		tmp = *alist;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
	}
}