/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:59:45 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/19 15:29:45 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	p += ft_strlen(s);
	while ((unsigned char *)s != p && *p != (unsigned char)c)
		p--;
	if (*p != (unsigned char)c)
		return (NULL);
	return ((char *)p);
}
