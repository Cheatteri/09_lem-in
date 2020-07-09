/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:14:38 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/09 23:52:23 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void prip(t_mem *mem)
{
	t_path *path;
	t_trail *trail;
	int i = 0;

	path = mem->paths;
	while(path[i].i_first != -1)
	{
		ft_printf("name='%s'",path[i].name);
		trail = path[i].rooms;
		while (trail)
		{
			ft_printf("%s,", trail->room->name);
			trail = trail->prev;
		}
		ft_printf("\n'i%d'\n",i);
		i++;
	}
}	

void pril(t_mem *mem)
{
	int i = 0, count = 0;
	int j;

	while (i < mem->n_rooms * 2)
	{
		j = 0;
		while (j < mem->n_rooms * 2)
		{
			if (mem->links[i][j] == 1)
				count++;
			ft_printf("%d,", mem->links[i][j++]);
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\nDDD%d\n", count);
}

void prir(t_mem *mem)
{
	int i = 0;
	while (i < mem->n_rooms)
	{
		ft_printf("%s, %d\n", mem->rooms[i].name, mem->rooms[i].w);
		i++;
	}
}

void	print_rows(t_mem *mem)
{
	t_row *row;

	rev_rows(mem);
	row = mem->rows;
	while (row)
	{
//		ft_putnbr(row->n_row);
		ft_putendl(row->line);
		row = row->next;
	}
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
//	system("leaks lem-in");
	exit(0);
}

int		main(int ac, char **av)
{
	t_mem *mem;

	if (ac > 2)
		ft_printf("usage: ./lem-in < source_file\n");
	else
	{
		mem = ft_init();
//		prir(mem);
//		pril(mem);
		if (mem->links[OUT(mem->start)][IN(mem->end)] == 1)
			ft_printf("-----------suora-----------\n");
		find_path(mem);
//		print_rows(mem);
		ft_printf("%s\n", av[0]);
	}
//	system("leaks lem-in");
	return (0);
}
