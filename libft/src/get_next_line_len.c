/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:12:25 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/12 14:37:30 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	use_line(char **str, char **line)
{
	char	*tmp;
	int		j;

	j = 0;
	while ((*str)[j] != '\n' && (*str)[j] != '\0')
		j++;
	if ((*str)[j] == '\n')
	{
		*line = ft_strsub(*str, 0, j);
		tmp = ft_strdup(&(*str)[j + 1]);
		free(*str);
		*str = tmp;
		if (*str[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

int			get_next_line_len(const int fd, char **line, int len)
{
	static char	*str[1023];
	char		c[len + 1];
	int			i;
	char		*tmp;

	if (fd < 0)
		return (-1);
	while ((i = read(fd, c, len)) > 0)
	{
		c[i] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(c);
		else
		{
			tmp = ft_strjoin(str[fd], c);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (i == 0 && str[fd] == NULL)
		return (0);
	return (i < 0 ? (-1) : use_line(&str[fd], line));
}
