/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:26:51 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/22 21:34:57 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				push_swap_next(t_push_swap_data *data, char spec)
{
	t_push_swap_list	*stack_tmp;
	t_push_swap_list	*stack;
	int					r;
	int					rr;

	if (spec == 'a')
		stack = data->stack_a;
	else
		stack = data->stack_b;
	r = 0;
	stack_tmp = stack;
	while (stack_tmp->group != data->group && (size_t)ft_abs(r) <= data->stack_size)//TODO assure that length counter was added
	{
		stack_tmp = stack_tmp->next;
		++r;
	}
	data->stack_next = stack_tmp;
	stack_tmp = stack;
	rr = 0;
	while (stack_tmp->group != data->group && (size_t)ft_abs(rr) <= data->stack_size)
	{
		stack_tmp = push_swap_prev(stack_tmp, 0);
		--rr;
	}
	if (ft_abs(r) > ft_abs(rr))
		data->stack_next = stack_tmp;
	return ((ft_abs(r) <= ft_abs(rr)) ? r : rr);
}

int				push_swap_sorted(t_push_swap_list *stack, size_t group)
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

static int		push_swap_base_avg(t_push_swap_list *stack, size_t group)
{
	t_push_swap_list	*stack_tmp;
	int					n;
	int					avg;

	n = 1;
	while (stack->group != group)
		stack = stack->next;
	avg = stack->value;
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->group == group)
		{
			avg += stack_tmp->value;
			++n;
		}
		stack_tmp = stack_tmp->next;
	}
	return (avg / n);
}

static int		push_swap_get_avg(t_push_swap_list *stack, int avg,
				size_t group)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = stack;
	if (stack_tmp->group == group && avg == stack_tmp->value)
		return (1);
	stack_tmp = stack_tmp->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->group == group && avg == stack_tmp->value)
			return (1);
		stack_tmp = stack_tmp->next;
	}
	return (0);
}

int				push_swap_avg(t_push_swap_list *stack, size_t group)
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
