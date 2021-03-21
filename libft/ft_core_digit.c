/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:56 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_core_digit(char *str, t_flags *flags, va_list *args)
{
	flags->size = ft_atoi_abs(str);
	while (ft_isdigit(*str))
		str++;
	if (ft_isterminator(*str))
		return (ft_core_print(str, flags, args));
	else if (*str == '.' && flags->point == -1)
		return (ft_core_point(str, flags, args));
	return (-1);
}
