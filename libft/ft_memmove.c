/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:31:53 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_src;
	char	*p_dest;
	size_t	i;

	if (!dest && !src)
		return (dest);
	p_src = (char *)src;
	p_dest = (char *)dest;
	i = 0;
	if (p_dest > p_src)
		while (n-- > 0)
			p_dest[n] = p_src[n];
	else
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	return (dest);
}
