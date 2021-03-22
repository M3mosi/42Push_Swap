/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:41:48 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 23:13:17 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "libft/libft.h"

# define MIN_INT	-2147483648
# define MAX_INT	2147483647

int		is_double(int *arr, int i, int n)
{
	int k;

	k = 0;
	while (k < i)
	{
		if (arr[k] == n)
			return (0);
		k++;
	}
	return (1);
}

int		generate_random(int *arr, int i)
{
	int n;

	while (1)
	{
		//srand();
		n = (rand() % (MAX_INT - MIN_INT)) + MIN_INT;
		if (is_double(arr, i, n))
			break;
	}
	return (n);
}

void	make_random(int n)
{
	int i;
	int *arr;

	arr = calloc(n + 1, sizeof(int));
	i = 0;
	while (i < n)
	{
		arr[i] = generate_random(arr, i);
		printf("%d ", arr[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	make_random(atoi(argv[1]));
}
