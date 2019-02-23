/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:36:24 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/23 13:19:41 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap_list	*push_swap_prev(t_push_swap_list *stack, size_t group)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = stack;
	if (group == 0)
	{
		while (stack_tmp && stack_tmp->next != stack)
			stack_tmp = stack_tmp->next;
	}
	else
	{
		while (stack_tmp && stack_tmp->next->group != stack->group)
			stack_tmp = stack_tmp->next;
	}
	return (stack_tmp);
}

void				push_swap_free_stack(t_push_swap_list **stack)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = push_swap_prev(*stack, 0);
	if (stack_tmp)
		stack_tmp->next = NULL;
	while (*stack)
	{
		stack_tmp = (*stack)->next;
		ft_memdel((void**)stack);
		if (stack_tmp)
			*stack = stack_tmp;
	}
}

size_t				push_swap_stack_size(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp;
	size_t				size;

	if (!stack)
		return (0);
	size = 1;
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		stack_tmp = stack_tmp->next;
		++size;
	}
	return (size);
}

int					push_swap_sorted_a(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp;
	t_push_swap_list	*stack_prev;

	stack_prev = stack;
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		if (stack_prev->value > stack_tmp->value)
			return (0);
		stack_prev = stack_prev->next;
		stack_tmp = stack_tmp->next;
	}
	return (1);
}
