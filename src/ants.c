/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:34:36 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/09 23:50:51 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	init_ants(t_path *paths)
{
	int i;

	i = 0;
	while (paths[i].i_first != -1)
	{
		paths[i].nb_ants = 0;
		paths[i].nb_remaining = 0;
		i++;
	}
	paths[i].nb_ants = -1;
	paths[i].nb_remaining = -1;
}

void	put_ants_to_paths( t_path **paths, int *i, int *ants)
{
	while (ants)
	{
		if ((*paths)[*i].w + (*paths)[*i].nb_ants + 1 <= (*paths)[0].w + (*paths)[0].nb_ants)
		{
			(*paths)[*i].nb_ants++;
			(*paths)[*i].nb_remaining++;
			(*ants)--;
		}
		else
			break ;
	}
	(*i)++;
}

void	set_ants_per_room(t_mem *mem, t_path *paths)
{
	int ants;
	int i;

	ft_printf("HERE1\n");
	ants = mem->n_ants;
	init_ants(paths);
	while (ants)
	{
		i = 1;
		while (ants && paths[i].i_first != -1)
			put_ants_to_paths(&paths, &i, &ants);
		if (ants)
		{
			paths[0].nb_ants++;
			paths[0].nb_remaining++;
			ants--;
		}
	}
	ft_printf("HERE2\n");
}
