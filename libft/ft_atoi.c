/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:23:29 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	long int		sum;
	int				negative;
	int				count;

	sum = 0;
	negative = 1;
	count = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			negative = -1;
	while (ft_isdigit(*nptr))
	{
		sum *= 10;
		sum += *nptr++ - '0';
		if (negative == -1 && sum < 0)
			return (0);
		if (negative == 1 && sum < 0)
			return (-1);
		count++;
	}
	if (count == 0)
		return (-1);
	return (sum * negative);
}
