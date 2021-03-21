/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:32:33 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/21 21:14:53 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnbr(const char *str)
{
	if(*str == '-' || *str ==  '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == 0)
		return (1);
	return (0);
}