/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:39:50 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 17:41:34 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	search(t_mem *mem, t_link *link)
{
	int		i;
	int		s;
	int		e;
	t_room	*room;

	s = 0;
	e = 0;
	i = 0;
	while (i < mem->n_rooms)
	{
		room = &mem->rooms[i++];
		if (ft_strcmp(room->name, link->start) == 0 && s == 0)
		{
			link->id_start = room->id;
			s = 1;
		}
		else if (ft_strcmp(room->name, link->end) == 0 && e == 0)
		{
			link->id_end = room->id;
			e = 1;
		}
		else if (link->id_start != -1 && link->id_end != -1)
			break ;
	}
}

void	set_rooms_to_links(t_mem *mem)
{
	t_room	*room;
	int		i;

	i = 0;
	while (i < mem->n_rooms)
	{
		room = &mem->rooms[i++];
		mem->links[OUT(room->id)][IN(room->id)] = 1;
		mem->links[IN(room->id)][OUT(room->id)] = 1;
	}
}

void	make_links(t_mem *mem)
{
	t_link	*link;
	int		i;
	int		j;

	i = -1;
	while (++i < mem->n_rooms * 2)
	{
		mem->links[i] = (int*)malloc(sizeof(int) * (mem->n_rooms * 2));
		j = 0;
		while (j < mem->n_rooms * 2)
			mem->links[i][j++] = 0;
	}
	set_rooms_to_links(mem);
	link = mem->l_lst;
	while (link)
	{
		if (ft_strcmp(link->start, link->end) != 0)
			search(mem, link);
		if (link->id_start != -1 && link->id_end != -1)
		{
			mem->links[OUT(link->id_start)][IN(link->id_end)] = 1;
			mem->links[OUT(link->id_end)][IN(link->id_start)] = 1;
		}
		link = link->next;
	}
}
