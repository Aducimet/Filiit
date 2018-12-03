/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 11:49:32 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 15:44:12 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fillit.h"
#include <stdio.h>
#include <fcntl.h>

char	**create_map(int size)
{
	char	**map;
	int		index;

	index = 0;
	if ((map = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (index < size)
	{
		if (!(map[index] = ft_strnew(size)))
			return (NULL);
		ft_memset(map[index], '.', size);
		index++;
	}
	map[index] = NULL;
	return (map);
}

int		resolve(char **map, int map_size, t_tetri **afirst, char letter)
{
	t_tetri *tmp;
	t_point	test;

	tmp = *afirst;
	test = new_point(0, 0);
	if (!tmp)
		return (1);
	while (test.y < map_size)
	{
		test.x = 0;
		while (test.x < map_size)
		{
			if (try_place_tetri(map, map_size, tmp, test) == 1)
			{
				place_tetri(map, tmp, test, letter);
				if (resolve(map, map_size, &tmp->next, letter + 1) == 1)
					return (1);
				delete_tetri(map, tmp, test);
			}
			test.x++;
		}
		test.y++;
	}
	return (0);
}

int		try_place_tetri(char **map, int map_size, t_tetri *list, t_point test)
{
	t_tetri *tmp;
	t_point	cube;
	int		k;

	k = 0;
	tmp = list;
	while (k < 4)
	{
		cube = new_point(tmp->list[k].x, tmp->list[k].y);
		if (!(cube.x + test.x < map_size) || !(cube.y + test.y < map_size) ||
			map[cube.y + test.y][cube.x + test.x] != '.')
			return (-1);
		k++;
	}
	return (1);
}

int		place_tetri(char **map, t_tetri *list, t_point test, char letter)
{
	t_tetri	*tmp;
	int		k;

	k = 0;
	tmp = list;
	while (k < 4)
	{
		map[tmp->list[k].y + test.y][tmp->list[k].x + test.x] = letter;
		k++;
	}
	return (1);
}

int		delete_tetri(char **map, t_tetri *list, t_point test)
{
	t_tetri	*tmp;
	int		k;

	k = 0;
	tmp = list;
	while (k < 4)
	{
		map[tmp->list[k].y + test.y][tmp->list[k].x + test.x] = '.';
		k++;
	}
	return (0);
}
