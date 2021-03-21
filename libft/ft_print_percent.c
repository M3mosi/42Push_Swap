/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:31 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_percent_tris(t_flags *flags)
{
	int count;

	count = 0;
	while (count < flags->size - ft_max(flags->point, 1))
		count += ft_putlchar(' ');
	while (flags->point > 1)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlchar('%');
	return (count);
}

static int		ft_print_percent_bis(t_flags *flags)
{
	int count;

	count = 0;
	while (flags->point > 1)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlchar('%');
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int				ft_print_percent(t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus)
		count = ft_print_percent_bis(flags);
	else if (!flags->zero || (flags->zero && flags->point > 0))
		count = ft_print_percent_tris(flags);
	else if (flags->zero)
	{
		while (count < flags->size - 1)
			count += ft_putlchar('0');
		count += ft_putlchar('%');
	}
	return (count);
}
