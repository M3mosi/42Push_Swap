/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:35 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_char(t_flags *flags, int c)
{
	int	count;

	count = 0;
	if (flags->minus)
	{
		count += ft_putlchar(c);
		while (flags->size > 1)
		{
			count += ft_putlchar(' ');
			flags->size -= 1;
		}
	}
	else
	{
		while (flags->size > 1)
		{
			count += ft_putlchar(' ');
			flags->size -= 1;
		}
		count += ft_putlchar(c);
	}
	return (count);
}
