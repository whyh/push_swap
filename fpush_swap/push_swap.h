/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:53:25 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/22 17:05:24 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "push_swap_typedefs.h"

void				push_swap_rr(t_push_swap_list **stack);
void				push_swap_rrr(t_push_swap_list **stack);
void				push_swap_ss(t_push_swap_list **stack);
void				push_swap_pp(t_push_swap_list **stack_from,
					t_push_swap_list **stack_to);
void				push_swap_free(t_push_swap_list **stack);
t_push_swap_list	*push_swap_prev(t_push_swap_list *stack, size_t group);
int					push_swap_sorted_a(t_push_swap_list *stack);
int					push_swap_sorted(t_push_swap_list *stack, size_t group);
int					push_swap_next(t_push_swap_data *data, char spec);
void				push_swap_swap(t_push_swap_data *data, char stack);
void				push_swap_rotate_rev(t_push_swap_data *data, char stack);
void				push_swap_rotate(t_push_swap_data *data, char stack);
void				push_swap_push(t_push_swap_data *data, char stack);
int					push_swap_avg(t_push_swap_list *stack, size_t group);
int					push_swap_parse(t_push_swap_list **stack, size_t argc,
					char **argv);

#endif
