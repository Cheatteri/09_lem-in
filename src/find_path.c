/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:10:51 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 18:11:13 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		get_path(t_mem *mem, t_trail **rooms, int index)
{
	int		next;
	t_trail	*link;
	int		ret;

	if (index != mem->end && index != mem->start)
	{
		link = new_trail(mem->rooms + index);
		*rooms = add_trail(link, *rooms);
	}
	if (index == mem->end)
		return (0);
	next = 0;
	while (next < mem->n_rooms)
	{
		if (mem->links[IN(index)][OUT(next)])
		{
			if ((ret = get_path(mem, rooms, next)) == -1)
				return (-1);
			return (ret + 1);
		}
		next++;
	}
	return (-1);
}

void	fill(t_mem *mem, t_path *paths, int n)
{
	int count;
	int i;

	count = 0;
	i = 2;
	while (i < mem->n_rooms)
	{
		if (mem->links[IN(mem->start)][OUT(i)])
		{
			paths[count].name = mem->rooms[i].name;
			paths[count].i_first = i;
			paths[count].rooms = NULL;
			paths[count].w = get_path(mem, &(paths[count].rooms), i);
			count++;
		}
		i++;
	}
	paths[n].name = NULL;
	paths[n].i_first = -1;
	paths[n].w = 0;
}

void	sort_path(int n, t_path *paths)
{
	int		i;
	t_path	tmp;

	while (n > -1)
	{
		i = 0;
		while (paths[i + 1].i_first != -1)
		{
			if (paths[i].w > paths[i + 1].w)
			{
				tmp = paths[i + 1];
				paths[i + 1] = paths[i];
				paths[i] = tmp;
			}
			i++;
		}
		n--;
	}
}

t_path	*set_path_len_list(t_mem *mem)
{
	int		n;
	int		i;
	t_path	*paths;

	n = 0;
	i = 2;
	while (i < mem->n_rooms)
	{
		if (mem->links[IN(mem->start)][OUT(i)])
			n++;
		i++;
	}
	paths = (t_path*)malloc(sizeof(t_path) * (n + 1));
	fill(mem, paths, n);
	sort_path(n, paths);
	return (paths);
}

void	find_path(t_mem *mem)
{
	int		stop;
	t_path	*cur;

	stop = 0;
	while (!stop && reset_weights(mem))
	{
		if ((stop = bfs(mem)) == -1 && mem->paths == NULL)
			ft_error("No path.\n", mem);
		else if (!stop)
		{
			if (!(cur = set_path_len_list(mem)))
				ft_error("Path error.\n", mem);
			ants_to_room(mem, cur);
			if (mem->paths == NULL || cur[0].nb_ants + cur[0].w <
				mem->paths[0].nb_ants + mem->paths[0].w)
			{
				free_paths(mem->paths);
				mem->paths = cur;
			}
			else
			{
				free_paths(cur);
				stop = 1;
			}
		}
	}
}
