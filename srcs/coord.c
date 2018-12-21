/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coord.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 19:42:39 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 16:25:40 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fillit.h"

t_point	get_abs_coord(char **tab)
{
	t_point first;
	t_point test;

	first = new_point(-1, -1);
	test = new_point(0, 0);
	while (test.y < 4)
	{
		test.x = 0;
		while (test.x < 4)
		{
			if (tab[test.y][test.x] == '#')
			{
				if (first.x == -1)
					first = new_point(test.x, test.y);
				else if (test.x < first.x)
					first.x = test.x;
			}
			test.x++;
		}
		test.y++;
	}
	return (first);
}

int		get_coord(char **tab, t_point **list)
{
	t_point test;
	t_point	abso;
	int		index;

	if (!(*list = ft_memalloc(sizeof(t_point) * 4)))
		return (-1);
	test = new_point(0, 0);
	abso = get_abs_coord(tab);
	index = 0;
	while (test.y < 4)
	{
		test.x = 0;
		while (test.x < 4)
		{
			if (tab[test.y][test.x] == '#')
			{
				(*list)[index] = new_point(test.x - abso.x, test.y - abso.y);
				index++;
			}
			test.x++;
		}
		test.y++;
	}
	return (1);
}
