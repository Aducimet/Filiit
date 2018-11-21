/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 13:42:49 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 20:51:32 by aducimet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		ft_first_read(int fd1)
{
	char	**tab;
	char	*line;
	int		count;

	count = 0;
	while (get_next_line(fd1, &line) > 0)
	{
		tab = ft_addline(tab, line, count);
		count++;
	}
	if (count == 0)
		return (-1);
	count--;
	if (ft_strlen(tab[count]) <= 1 || count > 130)
		return (-1);
	return (0);
}

int		ft_get_link(char **tab, t_point index)
{
	int		count;
	int		line_max;

	count = 0;
	line_max = 0;
	while (tab[line_max])
		line_max++;
	if (line_max != 4 && line_max != 5)
		return (-1);
	if ((index.x != 3) && (tab[index.y][index.x + 1]) == '#')
		count++;
	if ((index.x > 0) && (tab[index.y][index.x - 1]) == '#')
		count++;
	if ((index.y != 3) && (tab[index.y + 1][index.x]) == '#')
		count++;
	if ((index.y > 0) && (tab[index.y - 1][index.x]) == '#')
		count++;
	return (count);
}

int		ft_fillit_error(char **tab)
{
	static int	max;
	t_point		index;
	int			count;

	index = new_point(0, 0);
	count = 0;
	while (tab[index.y])
	{
		index.x = 0;
		while (tab[index.y][index.x])
		{
			if (tab[index.y][index.x] == '#')
				count += ft_get_link(tab, index);
			else if (!(tab[index.y][index.x] == '.'))
				return (-1);
			index.x++;
		}
		index.y++;
	}
	if ((count != 8 && count != 6))
		return (-1);
	return (++max > 26 ? -1 : 0);
}

int		ft_fill_tab(char ***tab, int fd)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	ret = 0;
	i = 0;
	if ((*tab = (char **)malloc(sizeof(char *) * (4 + 1))) == NULL)
		return (-1);
	while (i <= 4 && (ret = get_next_line(fd, &line)) > 0)
	{
		if (((*tab)[i] = (char *)malloc(sizeof(char) * (4 + 1))) == NULL)
			return (-1);
		if (ft_strlen(line) != 4 && ft_strlen(line) != 0)
			return (-1);
		else if ((i % 5 == 4 && ft_strlen(line) != 0))
			return (-1);
		(*tab)[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	if (ret == 0 && i == 0)
		return (0);
	return (ft_fillit_error(*tab) == -1 ? -1 : 1);
}

t_point	get_abs_coord(char **tab)
{
	t_point first;
	t_point test;

	first = new_point(-1, -1);              //pour savoir si c'est le premier '#'
	test = new_point(0, 0);
	while (test.y < 4)
	{
		test.x = 0;
		while (test.x < 4)
		{
			if (tab[test.y][test.x] == '#')
			{
				if (first.x == -1)                           //avec cette condition
					first = new_point(test.x, test.y);       //on assigne les coordonnees
				else if (test.x < first.x)
					first.x = test.x;						//on trouve le point le plus haut a gauche de la piece
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

	if(!(*list = ft_memalloc(sizeof(t_point) * 4)))
		return (-1);
	test = new_point(0, 0);
	abso = get_abs_coord(tab);         // on donne le point le plus haut de la piece 
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

int		main(int argc, char **argv)
{
	char	**tab;
	int		ret;
	int		fd1;
	int		fd;
	t_tetri		*first;
	/*t_tetri		*tmp;
	int	k;*/

	if (argc == 2)
	{
		first = NULL;
		if ((fd = open(argv[1], O_RDONLY)) < 0 || (fd1 = open(argv[1], O_RDONLY)) < 0 ||
		 ft_first_read(fd1) == -1)
			return (write(1, "error\n", 6));
		while ((ret = ft_fill_tab(&tab, fd)) > 0)
			if (add_tetri(&tab , &first) == -1)
				return (write(1, "error\n", 6));
		if (ret == -1)
			return (write(1, "error\n", 6));
		/*tmp = first;
		while (tmp)
		{
			k = 0;
			while (k < 4)
			{
				printf("[%d][%d]\n", tmp->list[k].y, tmp->list[k].x);
				k++;
			}
			printf("/////////\n");
			tmp = tmp->next;
		}*/
	}
	else
		ft_putendl_fd("usage: ./fillit need one argument", 1);
	return (0);
}
