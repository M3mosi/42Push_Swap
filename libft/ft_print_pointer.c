/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:27 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(t_flags *flags, size_t ptr)
{
	char	*num;
	int		count;

	if (!ptr)
		return (ft_print_pointer_null(flags));
	if (!(num = ft_itoa_base_unsigned_long(ptr, 16)))
		return (-1);
	count = 0;
	if (flags->minus)
	{
		count += ft_putlstr("0x", 2);
		count += ft_putlstr(num, ft_strlen(num));
		while (count < flags->size)
			count += ft_putlchar(' ');
	}
	else
	{
		while (count < flags->size - (int)ft_strlen(num) - 2)
			count += ft_putlchar(' ');
		count += ft_putlstr("0x", 2);
		count += ft_putlstr(num, ft_strlen(num));
	}
	free(num);
	return (count);
}
