/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:16:43 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 19:27:36 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		n_links(t_mem *mem, int index, int *cur)
{
	int n;
	int i;
	int j;

	i = 0;
	n = 0;
	if (cur)
	{
		while (!n && cur[i] != -1)
		{
			j = -1;
			while (++j < mem->n_rooms * 2)
				n += mem->rooms[j / 2].w < 2 ? mem->links[cur[i]][j] : 0;
			i++;
		}
	}
	else
	{
		while (i < mem->n_rooms * 2)
		{
			n += mem->links[index][i];
			i++;
		}
	}
	return (n);
}

int		process(t_mem *mem, int *next, int *cur, int i)
{
	int j;

	j = 0;
	while (j < mem->n_rooms * 2)
	{
		if (mem->links[cur[i]][j] == 1 && mem->rooms[j / 2].w < mem->speed)
		{
			if (j == IN(mem->start))
			{
				mem->links[cur[i]][IN(mem->start)] = 0;
				mem->links[IN(mem->start)][cur[i]] = 1;
				free(next);
				return (cur[i]);
			}
			next[mem->count++] = j;
			mem->rooms[j / 2].w++;
		}
		j++;
	}
	return (-1);
}

void	set_orientation(t_mem *mem, int *cur, int *j)
{
	int i;

	i = 0;
	while (cur[i] != -1)
	{
		if (mem->links[cur[i]][*j])
		{
			mem->links[cur[i]][*j] = 0;
			mem->links[*j][cur[i]] = 1;
			*j = cur[i];
			i = -1;
		}
		i++;
	}
}

int		bfs_recursive(t_mem *mem, int *cur)
{
	int *next;
	int i;
	int j;

	j = -1;
	if (n_links(mem, 0, cur))
	{
		next = (int*)malloc(sizeof(int) * (mem->n_rooms * mem->n_rooms));
		mem->count = 0;
		i = 0;
		while (cur[i] != -1)
		{
			if ((j = process(mem, next, cur, i)) != -1)
				return (j);
			i++;
		}
		next[mem->count++] = -1;
		j = bfs_recursive(mem, next);
		if (j >= 0)
			set_orientation(mem, cur, &j);
		free(next);
	}
	return (j);
}

int		bfs(t_mem *mem)
{
	int *start;
	int count;
	int i;
	int index;

	start = (int*)malloc(sizeof(int) * (n_links(mem, OUT(mem->end), NULL) + 1));
	count = 0;
	i = 1;
	while (++i < mem->n_rooms * 2)
	{
		if (mem->links[OUT(mem->end)][i] == 1)
		{
			start[count++] = i;
			mem->rooms[i / 2].w++;
		}
	}
	start[count] = -1;
	if ((index = bfs_recursive(mem, start)) >= 0)
	{
		mem->links[OUT(mem->end)][index] = 0;
		mem->links[index][OUT(mem->end)] = 1;
		index = 0;
	}
	free(start);
	return (index);
}
