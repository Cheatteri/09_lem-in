/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:22:52 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 17:43:41 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	ft_validate_info(t_mem *mem)
{
	if (!mem->r_lst)
		ft_error("Missing rooms\n", mem);
	else if (!mem->l_lst)
		ft_error("Missing links\n", mem);
	if (mem->start == -1)
		ft_error("No start point\n", mem);
	else if (mem->end == -1)
		ft_error("No end point\n", mem);
	if (mem->start >= mem->n_rooms)
		ft_error("Bad start point\n", mem);
	else if (mem->end >= mem->n_rooms)
		ft_error("Bad end point\n", mem);
	if (mem->start == mem->end)
		ft_error("Start and end points are same\n", mem);
}

int		get_ants(t_mem *mem)
{
	char	*line;
	int		res;

	res = 0;
	while (get_next_line_len(FROM, &line, 8) > 0)
	{
		if (line[0] != '#')
		{
			res = ft_atoi_mod(line);
			new_row(line, &mem->rows, mem);
			break ;
		}
		new_row(line, &mem->rows, mem);
	}
	if (res < 1)
		ft_error("Invalid number of ants\n", mem);
	return (res);
}

void	default_values(t_mem *mem)
{
	mem->start = -1;
	mem->end = -1;
	mem->n_rooms = 0;
	mem->n_rows = 0;
	mem->n_lines = 0;
	mem->speed = 3;
	mem->r_lst = NULL;
	mem->l_lst = NULL;
	mem->a_lst = NULL;
	mem->a_que = NULL;
	mem->rooms = NULL;
	mem->paths = NULL;
	mem->rows = NULL;
	mem->op = NULL;
	mem->tmp_count = 0;
}

void	room_arr(t_mem *mem)
{
	int		i;
	t_room	*room;

	mem->rooms = (t_room*)malloc(sizeof(t_room) * mem->n_rooms);
	i = 0;
	room = mem->r_lst;
	while (i < mem->n_rooms)
	{
		mem->rooms[i++] = *room;
		room = room->next;
	}
}

t_mem	*ft_init(char *str, int n)
{
	t_mem *mem;

	mem = NULL;
	mem = (t_mem*)malloc(sizeof(t_mem));
	default_values(mem);
	mem->op = options(str, n);
	mem->n_ants = get_ants(mem);
	parse_lines(mem);
	rev_rooms(mem);
	rev_links(mem);
	ft_validate_info(mem);
	room_arr(mem);
	start_end_rooms(mem);
	mem->links = (int**)malloc(sizeof(int*) * (mem->n_rooms * 2));
	make_links(mem);
	return (mem);
}
