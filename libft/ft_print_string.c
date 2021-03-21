/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:23:54 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_string_tris(t_flags *flags, char *str, int len)
{
	int count;

	count = 0;
	while (count < flags->size - ft_min(len, flags->point))
		count += ft_putlchar(' ');
	if (flags->point >= len)
		count += ft_putlstr(str, len);
	else
		count += ft_putlstr(str, flags->point);
	return (count);
}

static int		ft_print_string_bis(t_flags *flags, char *str, int len)
{
	int count;

	count = 0;
	if (flags->point >= len)
		count += ft_putlstr(str, len);
	else
		count += ft_putlstr(str, flags->point);
	while (count < flags->size)
		count += ft_putlchar(' ');
	return (count);
}

int				ft_print_string(t_flags *flags, char *str)
{
	int count;
	int len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->point <= -1)
		flags->point = len;
	if (flags->zero && flags->size == 0)
	{
		flags->size = flags->point;
		flags->point = -1;
	}
	count = 0;
	if (flags->minus)
		count = ft_print_string_bis(flags, str, len);
	else
		count = ft_print_string_tris(flags, str, len);
	return (count);
}
