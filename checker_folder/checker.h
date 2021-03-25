/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:34:26 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 11:56:13 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../pushswap.h"

void		read_file(t_stack *stack_a);
char		**line_taker(int fd);
t_stack		init_values_checker(t_stack stack_a);
void		end_checker(t_stack *stack_a, t_stack *stack_b);
int			ft_ok(t_stack *stack);

#endif
