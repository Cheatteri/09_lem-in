/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:49:46 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 18:24:58 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_room
{
	char			*name;
	char			*x;
	char			*y;
	int				id;
	int				pos;
	int				w;
	int				ant_id;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	char			*start;
	char			*end;
	int				id_start;
	int				id_end;
	struct s_link	*next;
}					t_link;

typedef struct		s_trail
{
	t_room			*room;
	struct s_trail	*next;
	struct s_trail	*prev;
}					t_trail;

typedef struct		s_path
{
	char			*name;
	int				i_first;
	int				w;
	int				nb_ants;
	int				nb_remaining;
	t_trail			*rooms;
}					t_path;

typedef struct		s_row
{
	char			*line;
	int				n_row;
	struct s_row	*next;
}					t_row;

typedef struct		s_ant
{
	int				name;
	int				turn;
	t_trail			*room;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_mem
{
	int				n_ants;
	int				n_rooms;
	int				n_rows;
	int				start;
	int				end;
	struct s_room	*r_lst;
	struct s_link	*l_lst;
	struct s_ant	*a_lst;
	struct s_ant	*a_que;
	struct s_ant	*tmp;
	int				**links;
	t_room			*rooms;
	t_path			*paths;
	struct s_row	*rows;
	int				count;
	int				n_lines;
	int				*op;
	int				speed;
}					t_mem;

#endif
