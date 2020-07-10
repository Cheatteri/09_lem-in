/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:07:51 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 16:46:04 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	rev_rows(t_mem *mem)
{
	t_row *prev;
	t_row *cur;
	t_row *next;

	prev = NULL;
	cur = mem->rows;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	mem->rows = prev;
}

void	rev_links(t_mem *mem)
{
	t_link *prev;
	t_link *cur;
	t_link *next;

	prev = NULL;
	cur = mem->l_lst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	mem->l_lst = prev;
}

void	rev_rooms(t_mem *mem)
{
	t_room *prev;
	t_room *cur;
	t_room *next;

	prev = NULL;
	cur = mem->r_lst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	mem->r_lst = prev;
}
