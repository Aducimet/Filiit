/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addline.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 20:15:35 by aducimet     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 12:06:27 by calin       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addline(char **tab, char *line, int size)
{
	char	**newtab;
	int		i;

	i = 0;
	if ((newtab = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (0);
	while (i < size)
	{
		newtab[i] = ft_strdup(tab[i]);
		i++;
	}
	newtab[i] = ft_strdup(line);
	return (newtab);
}
