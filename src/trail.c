/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trail.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:15:23 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 16:35:51 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_trail	*add_trail(t_trail *new, t_trail *alst)
{
	if (new == NULL)
		return (alst);
	if (alst == NULL)
		return (new);
	alst->next = new;
	new->prev = alst;
	return (new);
}

t_trail	*new_trail(t_room *room)
{
	t_trail *new;

	new = (t_trail*)malloc(sizeof(t_trail));
	new->room = room;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
