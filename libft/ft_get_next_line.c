/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:56:42 by dmalori           #+#    #+#             */
/*   Updated: 2021/02/14 10:50:40 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear(char *arr)
{
	int					i;

	i = 0;
	while (i < BUFFER_SIZE)
		arr[i++] = 0;
}

static int	ft_read_static(char *arr, char **line, char *line_new, int size)
{
	ssize_t			i;
	ssize_t			j;

	i = 0;
	j = ft_strlen(line_new);
	while (i < size)
	{
		if (arr[i] != 0)
		{
			if (arr[i] == '\n')
			{
				arr[i] = 0;
				*line = line_new;
				return (1);
			}
			line_new[j] = arr[i];
			arr[i] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_return(int code, char *arr, char *line_new, char **line)
{
	if (code == 0 || code == -1)
		ft_clear(arr);
	if (code == 0 || code == 1)
		*line = ft_strdup(line_new);
	free(line_new);
	return (code);
}

int			ft_get_next_line(int fd, char **line)
{
	static char		arr[MAX_FILES][BUFFER_SIZE];
	char			*line_new;
	ssize_t			tot_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if ((line_new = ft_calloc(BUFFER_SIZE + 1, sizeof(char))) == NULL)
		return (ft_return(-1, arr[fd], line_new, line));
	if (ft_read_static(arr[fd], line, line_new, BUFFER_SIZE) == 1)
		return (ft_return(1, arr[fd], line_new, line));
	while ((tot_read = read(fd, arr[fd], BUFFER_SIZE)) > 0)
	{
		if (line_new[0] != 0)
			if ((line_new = ft_recalloc(line_new, tot_read)) == NULL)
				return (ft_return(-1, arr[fd], line_new, line));
		if (ft_read_static(arr[fd], line, line_new, tot_read) == 1)
			return (ft_return(1, arr[fd], line_new, line));
	}
	if (tot_read != 0)
		return (ft_return(-1, arr[fd], line_new, line));
	return (ft_return(0, arr[fd], line_new, line));
}
