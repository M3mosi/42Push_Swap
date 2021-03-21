/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:02 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlstr(char *s, int len)
{
	int count;

	count = 0;
	if (len == -1)
	{
		while (*s)
			count += ft_putlchar(*s++);
	}
	else
	{
		while (*s && len)
		{
			count += ft_putlchar(*s++);
			len--;
		}
	}
	return (count);
}
