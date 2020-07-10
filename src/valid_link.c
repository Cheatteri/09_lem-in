/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:34:38 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 18:02:22 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_link	*init_link(char *line, t_link **alst, t_mem *mem)
{
	t_link	*link;
	int		i;
	int		j;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		ft_error("malloc_error\n", mem);
	i = 0;
	while (line[i] != '-')
		i++;
	j = i + 1;
	link->start = ft_strsub(line, 0, i);
	while (line[i])
		i++;
	link->end = ft_strsub(line, j, i - j);
	link->id_start = -1;
	link->id_end = -1;
	if (alst == NULL)
		link->next = NULL;
	else
	{
		link->next = *alst;
		*alst = link;
	}
	return (link);
}

int		is_good(char c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

int		valid_link(char *line)
{
	int i;
	int j;

	if (line[0] == 'L')
		return (1);
	i = 0;
	while (line[i] && is_good(line[i]) == 1 && line[i] != '-')
		i++;
	if (line[i] != '-' || i == 0)
		return (1);
	i++;
	j = i;
	if (line[i] == 'L')
		return (1);
	while (line[i] && is_good(line[i]) == 1 && line[i] != '-')
		i++;
	if (line[i] != '\0' || i == j)
		return (1);
	return (0);
}
