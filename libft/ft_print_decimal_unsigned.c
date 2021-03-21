/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_unsigned.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:31 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_decimal_unsigned_bis(
	t_flags *flags, char *num, int len)
{
	int count;

	count = 0;
	while (flags->point > len)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlstr(num, len);
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int				ft_print_decimal_unsigned(t_flags *flags, int n)
{
	char	*num;
	int		len;
	int		count;

	if (!n)
		return (ft_print_zero(flags));
	count = 0;
	if (!(num = ft_itoa_base_unsigned(n, 10)))
		return (-1);
	len = ft_strlen(num);
	if (flags->minus)
		count = ft_print_decimal_unsigned_bis(flags, num, len);
	else
	{
		while (count < flags->size - ft_max(flags->point, len))
			count += ft_putlchar(' ');
		while (flags->point > len)
		{
			count += ft_putlchar('0');
			flags->point -= 1;
		}
		count += ft_putlstr(num, len);
	}
	free(num);
	return (count);
}
