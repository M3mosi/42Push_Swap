/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:54 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_core_minus(char *str, t_flags *flags, va_list *args)
{
	str++;
	flags->minus = 1;
	if (ft_isdigit(*str))
	{
		flags->size = ft_atoi_abs(str);
		while (ft_isdigit(*str))
			str++;
	}
	else if (*str == '*')
	{
		flags->size = va_arg(*args, int);
		if (flags->size < 0)
		{
			flags->minus = 1;
			flags->size *= -1;
		}
		str++;
	}
	if (*str == '.')
		return (ft_core_point(str, flags, args));
	else if (ft_isterminator(*str))
		return (ft_core_print(str, flags, args));
	else if (*str == '-')
		return (ft_core_minus(str, flags, args));
	return (-1);
}
