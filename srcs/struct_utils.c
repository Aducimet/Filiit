/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 18:28:53 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 16:25:49 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fillit.h"

t_point	new_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_tetri	*new_tetri(void)
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

int		ft_list_len(t_tetri *list)
{
	int		size;
	t_tetri	*temp;

	size = 1;
	temp = list;
	while (temp->next)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

int		add_tetri(char ***atab, t_tetri **afirst)
{
	t_tetri *tmp;

	tmp = new_tetri();
	if (get_coord(*atab, &(tmp->list)) == -1)
		return (-1);
	add_elem(afirst, tmp);
	ft_2dstrdel(atab);
	return (1);
}
