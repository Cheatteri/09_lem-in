/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:22:52 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/09 00:56:55 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	ft_validate_info(t_mem *mem)
{
	if (!mem->r_lst)
		ft_error("ERROR: missing rooms\n");
	else if (!mem->l_lst)
		ft_error("ERROR: missing links\n");
	if (mem->start == -1)
		ft_putstr_fd("ERROR: no start point\n", 2);
	else if (mem->end == -1)
		ft_putstr_fd("ERROR: no end point\n", 2);
}

int		get_ants(t_mem *mem)
{
	char	*line;
	int		res;

	res = 0;
	while (get_next_line(FROM, &line) > 0)
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
		ft_error("Invalid number of ants\n");
	return (res);
}

void	default_values(t_mem *mem)
{
	mem->start = -1;
	mem->end = -1;
	mem->n_rooms = 0;
	mem->n_rows = 0;
	mem->r_lst = NULL;
	mem->l_lst = NULL;
	mem->rooms = NULL;
	mem->paths = NULL;
	mem->rows = NULL;
}

void	room_arr(t_mem *mem)
{
	int		i;
	t_room	*room;
	t_room	tmp;

	mem->rooms = (t_room*)malloc(sizeof(t_room) * mem->n_rooms);
	i = 0;
	room = mem->r_lst;
		ft_printf("%d,%d\n", mem->start, mem->end);
	while (i < mem->n_rooms)
	{
		mem->rooms[i++] = *room;
		room = room->next;
	}
	if (mem->start != 0)
	{
		tmp = mem->rooms[mem->start];
		mem->rooms[0].id = tmp.id;
		mem->rooms[mem->start] = mem->rooms[0];
		mem->rooms[0] = tmp;
		mem->rooms[0].id = 0;
		mem->start = 0;
	}
	ft_printf("%d,%d\n", mem->start, mem->end);
	if (mem->end != 1)
	{
		tmp = mem->rooms[mem->end];
		mem->rooms[1].id = tmp.id;
		mem->rooms[mem->end] = mem->rooms[1];
		mem->rooms[1] = tmp;
		mem->rooms[1].id = 1;
		mem->end = 1;
	}
	ft_printf("%d,%d\n", mem->start, mem->end);
}

t_mem	*ft_init(void)
{
	t_mem *mem;

	mem = NULL;
	mem = (t_mem*)malloc(sizeof(t_mem));
	default_values(mem);
	mem->n_ants = get_ants(mem);
	parse_lines(mem);
	room_arr(mem);
	make_links(mem);
//	id_arr(mem, mem->rooms, 0);
//	ft_validate_info(mem);

	
	return (mem);
}
