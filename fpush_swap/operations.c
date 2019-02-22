/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:13:26 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/17 21:08:24 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_rr(t_push_swap_list **stack)
{
	*stack = (*stack)->next;
}

void	push_swap_rrr(t_push_swap_list **stack)
{
	*stack = push_swap_prev(*stack, 0);
}

void	push_swap_ss(t_push_swap_list **stack)
{
	t_push_swap_list	*stack_tmp;
	t_push_swap_list	*stack_prev;

	stack_prev = push_swap_prev(*stack, 0);
	stack_tmp = (*stack)->next;
	stack_prev->next = stack_tmp;
	(*stack)->next = stack_tmp->next;
	stack_tmp->next = *stack;
	*stack = stack_tmp;
}

void	push_swap_pp(t_push_swap_list **stack_from, t_push_swap_list **stack_to)
{
	t_push_swap_list	*stack_tmp;
	t_push_swap_list	*stack_prev_from;
	t_push_swap_list	*stack_prev_to;

	stack_prev_from = push_swap_prev(*stack_from, 0);
	stack_prev_to = push_swap_prev(*stack_to, 0);
	stack_tmp = *stack_from;
	*stack_from = stack_tmp->next;
	stack_prev_from->next = stack_tmp->next;
	if (stack_prev_to)
		stack_prev_to->next = stack_tmp;
	if (*stack_to)
		stack_tmp->next = *stack_to;
	else
		stack_tmp->next = stack_tmp;
	*stack_to = stack_tmp;
	if (*stack_from == stack_prev_from && *stack_to == *stack_from)
		*stack_from = NULL;
}
