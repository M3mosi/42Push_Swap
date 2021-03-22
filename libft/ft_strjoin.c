/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:41:43 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 14:20:46 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char **s1, char const *s2, int mod)
{
	char	*p;
	char	*str;
	char	*s1_d;

	s1_d = *s1;
	if (!s1_d || !s2)
		return (NULL);
	if ((p = (char *)malloc(ft_strlen(s1_d) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	str = p;
	while (*s1_d)
		*p++ = *s1_d++;
	while (*s2)
		*p++ = *s2++;
	*p = 0;
	if (mod)
		free(*s1);
	return (str);
}
