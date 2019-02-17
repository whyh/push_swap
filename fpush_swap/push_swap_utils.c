/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:26:51 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/17 21:14:45 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				push_swap_next(t_push_swap_list *stack, size_t group)
{
	t_push_swap_list	*stack_tmp;
	int					r;
	int					rr;

	stack_tmp = stack;
	r = 0;
	while (stack_tmp->group != group)
	{
		stack_tmp = stack_tmp->next;
		++r;
	}
	stack_tmp = stack;
	rr = 0;
	while (stack_tmp->group != group)
	{
		stack_tmp = push_swap_prev(stack_tmp);
		--rr;
	}
	return ((ft_abs(r) <= ft_abs(rr)) ? r : rr);
}

int				push_swap_sorted_b(t_push_swap_list *stack, size_t group)
{
	t_push_swap_list	*stack_tmp;

	if (!stack)
		return (1);
	if (stack->group == group)
		return (0);
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->group == group)
			return (0);
		stack_tmp = stack_tmp->next;
	}
	return (1);
}

static int		push_swap_base_avg(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp;
	int					max;
	int					min;

	max = stack->value;
	min = stack->value;
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->value < min)
			min = stack_tmp->value;
		else if (stack_tmp->value > max)
			max = stack_tmp->value;
		stack_tmp = stack_tmp->next;
	}
	return ((min + max) / 2);
}

static int		push_swap_get_avg(t_push_swap_list *stack, int avg)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = stack;
	if (avg == stack_tmp->value)
		return (1);
	stack_tmp = stack_tmp->next;
	while (stack_tmp != stack)
	{
		if (avg == stack_tmp->value)
			return (1);
		stack_tmp = stack_tmp->next;
	}
	return (0);
}

int				push_swap_avg(t_push_swap_list *stack)
{
	int					err;
	int					avg;

	avg = push_swap_base_avg(stack);
	err = 0;
	while (stack)
	{
		if (push_swap_get_avg(stack, avg + err))
			return (avg + err);
		if (push_swap_get_avg(stack, avg - err))
			return (avg - err);
		++err;
	}
	return (0);
}
