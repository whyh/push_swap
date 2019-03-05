/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_avg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:32:48 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 21:32:48 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		push_swap_base_avg(t_push_swap_list *stack, int group)
{
	t_push_swap_list	*stack_tmp;
	int					n;
	int					avg;

	n = 1;
	while (stack->g != group)
		stack = stack->next;
	avg = stack->value;
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->g == group)
		{
			avg += stack_tmp->value;
			++n;
		}
		stack_tmp = stack_tmp->next;
	}
	return (avg / n);
}

static int		push_swap_get_avg(t_push_swap_list *stack, int avg,
				int group)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = stack;
	if (stack_tmp->g == group && avg == stack_tmp->value)
		return (1);
	stack_tmp = stack_tmp->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->g == group && avg == stack_tmp->value)
			return (1);
		stack_tmp = stack_tmp->next;
	}
	return (0);
}

int				push_swap_avg(t_push_swap_list *stack, int group)
{
	int	err;
	int	avg;

	while (push_swap_sorted(stack, group))
		--group;
	avg = push_swap_base_avg(stack, group);
	err = 0;
	while (stack)
	{
		if (push_swap_get_avg(stack, avg + err, group))
			return (avg + err);
		if (push_swap_get_avg(stack, avg - err, group))
			return (avg - err);
		++err;
	}
	return (0);
}
