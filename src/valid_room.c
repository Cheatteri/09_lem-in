/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:46:49 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/13 13:19:15 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		check_coord(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] > 47 && str[i] < 58)
		i++;
	if (str[i] != '\0')
		return (-1);
	return (1);
}

void	free_room(t_room *room)
{
	free(room->name);
	free(room->x);
	free(room->y);
	free(room);
}

t_room	*init_room(int pos, char **str, t_mem *mem, t_room **alst)
{
	t_room *room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		ft_error("malloc_error\n", mem);
	room->name = ft_strdup(str[0]);
	room->x = ft_strdup(str[1]);
	room->y = ft_strdup(str[2]);
	room->id = mem->n_rooms;
	room->pos = pos;
	room->w = 0;
	room->ant_id = 0;
	if (alst == NULL)
		room->next = NULL;
	else
	{
		room->next = *alst;
		*alst = room;
	}
	if (check_coord(str[1]) == -1 || check_coord(str[2]) == -1)
	{
		free_room(room);
		return (NULL);
	}
	return (room);
}

int		valid_room(char *line, t_mem *mem, int pos)
{
	char	**str;
	int		i;
	int		res;

	if (line[0] == 'L')
		return (1);
	res = 0;
	str = ft_strsplit(line, ' ');
	i = 0;
	while (str[i] != NULL)
		i++;
	if (i != 3)
		res = 1;
	else
	{
		if (init_room(pos, str, mem, &mem->r_lst) == NULL)
			res = 1;
		mem->n_rooms++;
	}
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
	return (res);
}
