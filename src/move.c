/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:10:54 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 17:44:37 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	from_start_to_end(t_mem *mem)
{
	int ant;
	int n;

	ant = mem->n_ants;
	n = 1;
	write(1, "\n", 1);
	while (n <= ant)
	{
		ft_printf("L%d-%s", n, mem->rooms[1].name);
		if (n < ant)
			write(1, " ", 1);
		n++;
	}
	write(1, "\n", 1);
}

void	new_ant(t_ant **alst, int name)
{
	t_ant *new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->name = name;
	new->turn = -1;
	new->room = NULL;
	if (alst == NULL)
		new->next = NULL;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}

void	rewind_paths(t_mem *mem)
{
	t_path	*paths;
	t_trail	*link;
	int		i;

	i = 0;
	paths = mem->paths;
	while (paths[i].first != -1)
	{
		link = paths[i].rooms;
		while (link->prev)
			link = link->prev;
		paths[i].rooms = link;
		i++;
	}
}

void	give_paths_to_ants(t_mem *mem, t_ant *a)
{
	int i;
	int turn;

	turn = 1;
	while (a)
	{
		i = 0;
		while (mem->paths[i].first != -1 && a)
		{
			if (mem->paths[i].n_remaining > 0)
			{
				a->room = mem->paths[i].rooms;
				a->turn = turn;
				mem->paths[i].n_remaining--;
			}
			i++;
			if (a->room)
				a = a->next;
		}
		turn++;
	}
	mem->count = turn;
}

void	move_ants(t_mem *mem)
{
	int ant;

	ant = mem->n_ants;
	while (ant > 0)
		new_ant(&mem->a_lst, ant--);
	mem->tmp = mem->a_lst;
	rewind_paths(mem);
	give_paths_to_ants(mem, mem->a_lst);
}
