/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:05:03 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/09 23:44:42 by jhakala          ###   ########.fr       */
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

// vaihda ft_printf pois isolla mapil tulostus tekee 27.0s ja print 1.8s

void		ft_error(char *str);
t_mem		*ft_init(void);

/*
** utils.c
*/
int 	reset_weights(t_mem *mem);

void pril(t_mem *mem); //in main->poista
void prir(t_mem *mem); //in main->poista
void prip(t_mem *mem); //in main->poista

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
t_link		*init_link(char *line, t_link **alst);

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
void		set_ants_per_room(t_mem *mem, t_path *paths);

#endif
