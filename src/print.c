/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:23:32 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/13 12:26:26 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_rows(t_mem *mem)
{
	t_row *row;

	rev_rows(mem);
	row = mem->rows;
	while (row)
	{
		ft_printf("%s\n", row->line);
		row = row->next;
	}
}

void	print_link_map(t_mem *mem)
{
	int i;
	int j;

	i = 0;
	while (i < mem->n_rooms * 2)
	{
		j = 0;
		while (j < mem->n_rooms * 2)
		{
			ft_putnbr(mem->links[i][j++]);
			write(1, ",", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_paths(t_mem *mem)
{
	t_path	*path;
	t_trail	*trail;
	int		i;
	int		count;

	path = mem->paths;
	i = 0;
	while (path[i].first != -1)
	{
		count = 1;
		trail = path[i].rooms;
		ft_printf("NUMBER[%d]: ", i);
		while (trail)
		{
			ft_printf(" %s,", trail->room->name);
			trail = trail->next;
			count++;
		}
		ft_printf(" %s. LEN[%d]\n", mem->rooms[mem->end].name, count);
		i++;
	}
}

void	print_que(t_mem *mem, t_ant **alst)
{
	t_ant *a;

	a = *alst;
	while (a)
	{
		if (!a->room)
		{
			ft_printf("L%d-%s", a->name, mem->rooms[1].name);
			free_from_que(&a, mem);
		}
		else
		{
			ft_printf("L%d-%s", a->name, a->room->room->name);
			a->room = a->room->next;
		}
		if (a->next)
			write(1, " ", 1);
		a = a->next;
	}
	mem->n_lines++;
	write(1, "\n", 1);
}

void	print_turns(t_mem *mem)
{
	t_ant	*a;
	int		turn;

	a = mem->a_lst;
	turn = 1;
	write(1, "\n", 1);
	while (turn < mem->count)
	{
		while (a)
		{
			if (a->turn == turn)
				send_ant_to_que(a, &mem->a_lst, mem);
			else
				break ;
			a = mem->a_lst;
		}
		print_que(mem, &mem->a_que);
		turn++;
	}
	while (mem->a_que)
		print_que(mem, &mem->a_que);
}
