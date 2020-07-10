/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:30:07 by jhakala           #+#    #+#             */
/*   Updated: 2020/07/10 19:43:05 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi_mod(const char *str)
{
	size_t	res;
	int		minus;

	minus = 1;
	res = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
		minus = -1;
	if ((*str == '+' || *str == '-') && (*str + 1 > 47 || *str + 1 < 58))
		str++;
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if ((*str > 57 || *str < 48) && *str != '\0')
		return (0);
	if (res > 9223372036854775807)
		return (0);
	if (res > 2147483647 || minus == -1)
		return (0);
	return (res * minus);
}
