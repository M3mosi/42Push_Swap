/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:24:16 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numberlen(long int n)
{
	int			i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*p;
	int			count;
	int			negative;
	long int	conversion;

	conversion = (long int)n;
	negative = conversion < 0 ? -1 : 1;
	count = ft_numberlen(conversion);
	if ((p = (char *)malloc((count + 1) * sizeof(char))) == NULL)
		return (NULL);
	conversion *= negative;
	if (negative == -1)
		p[0] = '-';
	p[count] = 0;
	while (conversion)
	{
		p[--count] = conversion % 10 + '0';
		conversion /= 10;
	}
	if (n == 0)
		p[0] = '0';
	return (p);
}
