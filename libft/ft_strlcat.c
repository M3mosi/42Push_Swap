/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:46:22 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/19 15:54:25 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	dstlen = ft_strlen(dest);
	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while ((i + dstlen + 1) < size && src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	if (size > dstlen)
		return (dstlen + ft_strlen(src));
	return (size + ft_strlen(src));
}
