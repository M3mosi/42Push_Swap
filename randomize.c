/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:41:48 by forsili           #+#    #+#             */
/*   Updated: 2021/03/23 10:58:03 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "libft/libft.h"

# define MAX_INT	10000
# define MIN_INT	-MAX_INT

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
	srand(time(NULL));

	while (1)
	{
		n = (rand() % (MAX_INT - MIN_INT + 1))  + MIN_INT;
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
