/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:59:15 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 18:15:35 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		*fill_op(char *str, int *op)
{
	int i;
	int check;

	check = 0;
	if (str[0] != '-')
		ft_error("Missing '-' before flag(s).\n", NULL);
	i = 0;
	while (str[++i])
	{
		if (str[i] == 'h')
			check = 1;
		if (is_that_char(str[i], OPTION_CHARS) == 0)
			ft_error("Invalid flag char(s)\n", NULL);
	}
	if (check == 1)
		ft_error("usage: ./asm [-f] source_file\n", NULL);
	i = 0;
	while (str[++i])
		op[122 - str[i]] = 1;
	return (op);
}

int		*options(char *str, int n)
{
	int *op;
	int i;

	if (!(op = (int*)malloc(sizeof(int) * 26)))
	{
		ft_printf("Malloc error.\n");
		exit(0);
	}
	i = 0;
	while (i < 26)
		op[i++] = 0;
	if (n < 2)
		return (op);
	return (fill_op(str, op));
}

void	start_end_rooms(t_mem *mem)
{
	t_room tmp;

	if (mem->start != 0)
	{
		tmp = mem->rooms[mem->start];
		mem->rooms[0].id = tmp.id;
		mem->rooms[mem->start] = mem->rooms[0];
		mem->rooms[0] = tmp;
		mem->rooms[0].id = 0;
		mem->start = 0;
	}
	if (mem->end != 1)
	{
		tmp = mem->rooms[mem->end];
		mem->rooms[1].id = tmp.id;
		mem->rooms[mem->end] = mem->rooms[1];
		mem->rooms[1] = tmp;
		mem->rooms[1].id = 1;
		mem->end = 1;
	}
}

void	send_ant_to_que(t_ant *a, t_ant **alst, t_mem *mem)
{
	t_ant *que;

	*alst = a->next;
	a->next = NULL;
	que = mem->a_que;
	while (que && que->next)
		que = que->next;
	if (!que)
		mem->a_que = a;
	else
		que->next = a;
}

int		reset_weights(t_mem *mem)
{
	int i;

	i = 0;
	while (i < mem->n_rooms)
		mem->rooms[i++].w = 0;
	if (mem->op[7] == 1)
		mem->speed = 2;
	return (1);
}
