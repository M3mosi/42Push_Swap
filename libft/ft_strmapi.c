/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:49:33 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/18 09:44:24 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	if ((res = ft_strdup(s)) == NULL)
		return (NULL);
	while (*s)
	{
		res[i] = f(i, *s++);
		i++;
	}
	res[i] = 0;
	return (res);
}
