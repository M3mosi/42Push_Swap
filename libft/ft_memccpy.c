/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:27:06 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	unsigned char	p_c;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	p_c = (unsigned char)c;
	while (n)
	{
		*p_dest = *p_src;
		if (*p_src == p_c)
		{
			*p_dest++ = *p_src;
			return ((void *)p_dest);
		}
		p_dest++;
		p_src++;
		n--;
	}
	return (NULL);
}
