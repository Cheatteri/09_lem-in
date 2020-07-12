/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:34:36 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 17:36:19 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	init_ants(t_path *paths)
{
	int i;

	i = 0;
	while (paths[i].first != -1)
	{
		paths[i].n_ants = 0;
		paths[i].n_remaining = 0;
		i++;
	}
	paths[i].n_ants = -1;
}

void	ants_to_paths(t_path *paths, int *i, int *ants)
{
	while (ants)
	{
		if (paths[*i].w + paths[*i].n_ants < paths[0].w + paths[0].n_ants)
		{
			paths[*i].n_ants++;
			paths[*i].n_remaining++;
			(*ants)--;
		}
		else
			break ;
	}
	(*i)++;
}

void	ants_to_room(t_mem *mem, t_path *paths)
{
	int ants;
	int i;

	ants = mem->n_ants;
	init_ants(paths);
	while (ants)
	{
		i = 1;
		while (ants && paths[i].first != -1)
			ants_to_paths(paths, &i, &ants);
		if (ants)
		{
			paths[0].n_ants++;
			paths[0].n_remaining++;
			ants--;
		}
	}
}
