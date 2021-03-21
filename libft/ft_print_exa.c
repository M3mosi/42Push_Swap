/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:29 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_exa_tris(t_flags *flags, char *num, int len)
{
	int count;

	count = 0;
	while (count < flags->size - ft_max(flags->point, len))
		count += ft_putlchar(' ');
	while (flags->point > len)
	{
		count += ft_putlchar('0');
		flags->point -= 1;
	}
	count += ft_putlstr(num, len);
	return (count);
}

static int	ft_print_exa_bis(t_flags *flags, char *num, int len)
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

int			ft_print_exa(t_flags *flags, size_t n, int u)
{
	char	*num;
	int		count;
	int		len;

	if (!n)
		return (ft_print_zero(flags));
	count = 0;
	if (!(num = ft_itoa_base_unsigned(n, 16)))
		return (-1);
	if (u)
		num = ft_toupperstr(num);
	len = ft_strlen(num);
	if (flags->minus)
		count = ft_print_exa_bis(flags, num, len);
	else
		count = ft_print_exa_tris(flags, num, len);
	free(num);
	return (count);
}
