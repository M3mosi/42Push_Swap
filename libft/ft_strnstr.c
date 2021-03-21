/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:55:47 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/18 09:44:25 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	if (!(*needle))
		return ((char *)(haystack));
	while (i < len && haystack[i])
	{
		temp = i;
		while (needle[j] == haystack[i] && needle[j] &&
		haystack[i] && i < len)
		{
			j++;
			i++;
		}
		if (needle[j] == 0)
			return ((char *)&haystack[temp]);
		i = temp + 1;
		j = 0;
	}
	return (NULL);
}
