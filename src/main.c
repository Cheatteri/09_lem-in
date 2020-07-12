/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:14:38 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 18:03:41 by jhakala          ###   ########.fr       */
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
	if (mem->op[9] == 1 && mem->tmp_count > 0)
	{
		ft_printf("#Here is the number of");
		ft_printf(" lines required: %d\n", mem->tmp_count);
	}
}

/*
** flags:
** -a	show number of ants at the end
** -e	show error message, incase of error
** -f	show leaks
** -h	show how to use
** -l	show link map for debug
** -n	show number of result rows
** -p	show path combination
** -q	show requested line count, if input had it
** -r	doesn't show input rows
** -s	make it faster but, possibly less accurate in big maps
** -t	doesn't show result rows
*/

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
			move_ants(mem);
			print_all(mem);
		}
	}
	if (mem->op[20] == 1)
		system("leaks lem-in");
	return (0);
}
