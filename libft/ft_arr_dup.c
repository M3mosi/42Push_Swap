/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:31:06 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/23 16:30:12 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					*ft_arr_dup(int *arr, int len)
{
	int 	i;
	int 	*out;

	out = malloc((len + 2) * sizeof(int));
	i = 0;
	while (i < len)
	{
		out[i] = arr[i];
		i++;
	}
	return (out);
}