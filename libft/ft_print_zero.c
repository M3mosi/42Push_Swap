/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:22 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_zero_bis(t_flags *flags, char c, int len)
{
	int count;

	count = 0;
	while (flags->point > len)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	if (flags->point > 0 || flags->point == -1)
		count += ft_putlchar(c);
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int				ft_print_zero(t_flags *flags)
{
	int count;

	count = 0;
	if (flags->minus)
		count = ft_print_zero_bis(flags, '0', 1);
	else if (flags->point > 0 || flags->point == -1)
	{
		while (count < flags->size - ft_max(flags->point, 1))
			count += ft_putlchar(' ');
		while (flags->point > 1)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlchar('0');
	}
	else
	{
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	return (count);
}
