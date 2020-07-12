/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:23:06 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 17:45:59 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	new_row(char *line, t_row **alst, t_mem *mem)
{
	t_row *new;

	new = (t_row*)malloc(sizeof(t_row));
	new->line = line;
	new->n_row = mem->n_rows++;
	if (alst == NULL)
		new->next = NULL;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}

int		get_pos(char *line, t_mem *mem)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (mem->start != -1)
			ft_error("Too many start points.\n", mem);
		mem->start = mem->n_rooms;
		return (1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (mem->end != -1)
			ft_error("Too many end points.\n", mem);
		mem->end = mem->n_rooms;
		return (2);
	}
	else if (ft_strncmp(line, "#Here is the number of lines requi", 34) == 0)
		mem->tmp_count = ft_atoi(line + 38);
	return (0);
}

void	parse_lines(t_mem *mem)
{
	char	*line;
	int		pos;
	int		skip;

	pos = 0;
	skip = 0;
	while (get_next_line_len(FROM, &line, 10) > 0)
	{
		if (line[0] == '#')
			pos = get_pos(line, mem);
		else if (skip == 0 && valid_room(line, mem, pos) == 0)
			pos = 0;
		else if ((skip = 1) && valid_link(line) == 0)
			init_link(line, &mem->l_lst, mem);
		else
		{
			if (line[0] && line[0] != '\n')
				new_row(line, &mem->rows, mem);
			else
				free(line);
			break ;
		}
		new_row(line, &mem->rows, mem);
	}
}
