/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:20 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_return(va_list *args, int num)
{
	va_end(*args);
	return (num);
}

static int		ft_print_bis(char *str, t_flags *flags, va_list *args,
int count)
{
	int res;
	int *x;

	if (*str == '0')
		res = ft_core_zero(str, flags, args);
	else if (*str == '-')
		res = ft_core_minus(str, flags, args);
	else if (*str == '*')
		res = ft_core_star(str, flags, args);
	else if (*str == '.')
		res = ft_core_point(str, flags, args);
	else if (ft_isdigit(*str))
		res = ft_core_digit(str, flags, args);
	else if (*str == 'n')
	{
		x = va_arg(*args, int *);
		*x = count;
		res = 0;
	}
	else if (ft_isterminator(*str))
		res = ft_core_print(str, flags, args);
	else
		res = -1;
	return (res);
}

int				ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;
	int		res;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			count += ft_putlchar(*str);
		else
		{
			str++;
			flags = ft_initflags(flags);
			res = ft_print_bis((char *)str, &flags, &args, count);
			if (res == -1)
				return (ft_return(&args, -1));
			count += res;
			while (!ft_isterminator(*str))
				str++;
		}
		str++;
	}
	return (ft_return(&args, count));
}
