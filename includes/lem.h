/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:05:03 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 18:04:00 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "struct.h"

# define FROM 0
# define IN(x) (x * 2)
# define OUT(x) (x * 2 + 1)

# define OPTION_CHARS "aefhlnpqrst"

void		ft_error(char *str, t_mem *mem);
t_mem		*ft_init(char *str, int n);

/*
** utils.c
*/
int			*options(char *str, int n);
void		start_end_rooms(t_mem *mem);
void		send_ant_to_que(t_ant *a, t_ant **alst, t_mem *mem);
int			reset_weights(t_mem *mem);

/*
** parse.c
*/
void		new_row(char *line, t_row **alst, t_mem *mem);
void		parse_lines(t_mem *mem);

/*
** valid_*.c
*/
int			valid_room(char *line, t_mem *mem, int pos);
int			valid_link(char *line);
t_link		*init_link(char *line, t_link **alst, t_mem *mem);

void		make_links(t_mem *mem);

/*
** find_path.c
*/
void		find_path(t_mem *mem);
int			bfs(t_mem *mem);

/*
** rev.c
*/
void		rev_rows(t_mem *mem);
void		rev_links(t_mem *mem);
void		rev_rooms(t_mem *mem);

/*
** trail.c
*/
t_trail		*add_trail(t_trail *new, t_trail *alst);
t_trail		*new_trail(t_room *room);

/*
** ants.c
*/
void		ants_to_room(t_mem *mem, t_path *paths);

/*
** move.c
*/
void		from_start_to_end(t_mem *mem);
void		move_ants(t_mem *mem);

/*
** print.c
*/
void		print_rows(t_mem *mem);
void		print_link_map(t_mem *mem);
void		print_paths(t_mem *mem);
void		print_turns(t_mem *mem);

/*
** free.c
*/
int			is_that_char(char c, char *str);
void		free_from_que(t_ant **a, t_mem *mem);
void		free_paths(t_path *paths);

#endif
