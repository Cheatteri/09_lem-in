/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:14:38 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 20:00:28 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	ft_error(char *str, t_mem *mem)
{
	if (mem == NULL)
	{
		ft_putstr_fd(str, 2);
		exit(0);
	}
	if (mem->op && mem->op[21] == 1)
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putstr_fd(str, 2);
	}
	else
		ft_putstr_fd("ERROR.\n", 2);
	if (mem->op && mem->op[20] == 1)
		system("leaks lem-in");
	exit(0);
}

void	print_all(t_mem *mem)
{
	if (mem->op[8] == 0)
		print_rows(mem);
	if (mem->op[6] == 0)
		print_turns(mem);
	if (mem->op[10] == 1)
		print_paths(mem);
	if (mem->op[25] == 1)
		ft_printf("Number of ants: %d.\n", mem->n_ants);
	if (mem->op[12] == 1)
		ft_printf("Number of lines: %d.\n", mem->n_lines);
}

int		main(int ac, char **av)
{
	t_mem *mem;

	mem = NULL;
	if (ac > 2)
		ft_printf("usage: ./lem-in < source_file\n");
	else
	{
		mem = ft_init(av[1], ac);
		if (mem->op[14] == 1)
			print_link_map(mem);
		if (mem->links[OUT(mem->start)][IN(mem->end)] == 1)
		{
			print_rows(mem);
			from_start_to_end(mem);
		}
		else
		{
			find_path(mem);
//			exit(0);
			move_ants(mem);
			print_all(mem);
		}
	}
	if (mem->op[20] == 1)
		system("leaks lem-in");
	return (0);
}
