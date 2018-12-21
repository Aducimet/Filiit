/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 17:02:11 by calin        #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 16:25:43 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fillit.h"

void		ft_listdel(t_tetri **list)
{
	t_tetri *tmp;

	tmp = NULL;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->list);
		free(*list);
		*list = tmp;
	}
}

int			rccar(int nb)
{
	int nb_tmp;

	nb_tmp = nb / 2;
	while (nb_tmp * nb_tmp > nb)
		nb_tmp--;
	return (nb_tmp * nb_tmp == nb ? nb_tmp : nb_tmp + 1);
}
