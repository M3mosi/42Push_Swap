/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:36:53 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_recalloc(char *line_old, ssize_t plus)
{
	char				*line_new;
	int					i;

	i = 0;
	if (!(line_new = ft_calloc(ft_strlen(line_old) + plus + 1, sizeof(char))))
		return (NULL);
	while (line_old[i])
	{
		line_new[i] = line_old[i];
		i++;
	}
	free(line_old);
	return (line_new);
}
