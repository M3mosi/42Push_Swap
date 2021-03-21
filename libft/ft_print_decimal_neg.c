/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_neg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:33 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_decimal_neg_2(t_flags *flags, char *num, int len)
{
	int count;

	count = 0;
	while (count < flags->size - (ft_max(len, flags->point) + 1))
		count += ft_putlchar(' ');
	count += ft_putlchar('-');
	while (flags->point > len)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlstr(&num[1], len);
	return (count);
}

static int		ft_print_decimal_neg_1(t_flags *flags, char *num, int len)
{
	int count;

	count = ft_putlchar('-');
	while (flags->point > len)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlstr(&num[1], len);
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int				ft_print_decimal_neg(t_flags *flags, char *num)
{
	int		len;
	int		count;

	count = 0;
	len = ft_strlen(num) - 1;
	if (flags->minus)
		count = ft_print_decimal_neg_1(flags, num, len);
	else if (!flags->zero || (flags->zero && flags->size > 0))
		count = ft_print_decimal_neg_2(flags, num, len);
	else
	{
		while (count < flags->size - (ft_max(len, flags->point) + 1))
			count += ft_putlchar(' ');
		count += ft_putlchar('-');
		while (flags->point > len + 1)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlstr(&num[1], len);
	}
	free(num);
	return (count);
}
