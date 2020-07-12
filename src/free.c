/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:54:44 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 17:37:35 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		is_that_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

void	free_from_que(t_ant **a, t_mem *mem)
{
	t_ant *p;

	if (*a == mem->a_que)
		mem->a_que = (*a)->next;
	else
	{
		p = mem->a_que;
		while (p->next != *a)
			p = p->next;
		p->next = (*a)->next;
		free(*a);
		*a = p;
	}
}

void	free_paths(t_path *paths)
{
	int		i;
	t_trail	*rooms;
	t_trail	*prev;

	i = 0;
	if (paths)
	{
		while (paths[i].name != NULL)
		{
			rooms = paths[i].rooms;
			while (rooms)
			{
				prev = rooms->prev;
				free(rooms);
				rooms = prev;
			}
			i++;
		}
		free(paths);
	}
}
