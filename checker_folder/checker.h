/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:34:26 by forsili           #+#    #+#             */
/*   Updated: 2021/03/24 16:33:21 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../pushswap.h"

void		read_file(t_stack *stack_a);
char		**line_taker(int fd);
void		init_all(t_stack *stack_a);
void		free_result_unit(t_stack *stack_a, t_stack *stack_b);

#endif
