/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:41:48 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 15:10:17 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <time.h>
#include "pushswap.h"

#define MAX	10000
#define MIN	-10000

static int		is_double(int *arr, int i, int n)
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
		n = (rand() % (MAX - MIN + 1)) + MIN;
		if (is_double(arr, i, n))
			break ;
	}
	return (n);
}

void	make_random(int n)
{
	int i;
	int *arr;

	arr = ft_calloc(n + 1, sizeof(int));
	i = 0;
	while (i < n)
	{
		arr[i] = generate_random(arr, i);
		if (i != n - 1)
			ft_printf("%d ", arr[i]);
		else
			ft_printf("%d", arr[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	make_random(ft_atoi(argv[1]));
}
