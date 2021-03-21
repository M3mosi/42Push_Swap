/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:32:33 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_next(char **a, int *size, char c, int i)
{
	char	*start;

	*size = 0;
	start = NULL;
	while (a[0][i])
	{
		if (a[0][i] == c && start)
		{
			a[0] = start + *size;
			return (start);
		}
		else if (a[0][i] != c && !start)
			start = &a[0][i];
		if (a[0][i] != c)
			*size += 1;
		i++;
	}
	a[0] = start + *size;
	if (!(*size))
		return (0);
	return (start);
}

char			**ft_split(const char *s, char c)
{
	int		size;
	char	**m;
	char	*n;
	char	*a;
	int		i;

	if (!s)
		return (NULL);
	a = (char *)s;
	i = 0;
	while (ft_next(&a, &size, c, 0))
		i++;
	if (!(m = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	a = (char *)s;
	while ((n = ft_next(&a, &size, c, 0)))
	{
		if (!(m[i] = (char *)malloc((size + 1) * sizeof(char))))
			return (NULL);
		ft_strncpy(m[i++], n, size, 0);
	}
	m[i] = 0;
	return (m);
}
