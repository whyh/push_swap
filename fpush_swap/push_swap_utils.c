/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:26:51 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 21:35:16 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_next(t_push_swap_data data, t_push_swap_list *stack,
		t_push_swap_list **stack_next, t_push_swap_list *stack_avoid)
{
	t_push_swap_list	*stack_tmp;
	int					r;
	int					rr;

	r = 0;
	stack_tmp = stack;
	while ((stack_tmp->g != data.group || stack_tmp == stack_avoid)
	&& (size_t)ft_abs(r) <= data.stack_size)
	{
		stack_tmp = stack_tmp->next;
		++r;
	}
	*stack_next = stack_tmp;
	rr = 0;
	stack_tmp = stack;
	while ((stack_tmp->g != data.group || stack_tmp == stack_avoid)
	&& (size_t)ft_abs(rr) <= data.stack_size)
	{
		stack_tmp = push_swap_prev(stack_tmp, 0);
		--rr;
	}
	if (ft_abs(r) > ft_abs(rr))
		*stack_next = stack_tmp;
	return ((ft_abs(r) <= ft_abs(rr)) ? r : rr);
}

int		push_swap_sorted(t_push_swap_list *stack, int group)
{
	t_push_swap_list	*stack_tmp;

	if (!stack)
		return (1);
	if (stack->g == group)
		return (0);
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->g == group)
			return (0);
		stack_tmp = stack_tmp->next;
	}
	return (1);
}

void	push_swap_get_next(t_push_swap_data *data, char stack)
{
	int	next;

	if (stack == 'a')
		next = push_swap_next(*data, data->stack_a, &(data->stack_next), NULL);
	else
		next = push_swap_next(*data, data->stack_b, &(data->stack_next), NULL);
	while (next > 0)
	{
		push_swap_rotate(data, stack);
		--next;
	}
	while (next < 0)
	{
		push_swap_rotate_rev(data, stack);
		++next;
	}
}

size_t	push_swap_count_group(t_push_swap_list *stack, int group)
{
	size_t	stack_size;
	size_t	n;

	stack_size = push_swap_stack_size(stack);
	n = 0;
	while (stack_size > 0)
	{
		if (stack->g == group)
			++n;
		stack = stack->next;
		--stack_size;
	}
	return (n);
}

void	push_swap_group(t_push_swap_data *data, int group_targ, int group_new,
		char spec)
{
	t_push_swap_list	*stack;
	size_t				stack_size;

	if (spec == 'a')
		stack = data->stack_a;
	else
		stack = data->stack_b;
	stack_size = push_swap_stack_size(stack);
	while (stack_size)
	{
		if ((stack->g == group_targ || group_targ == 0)
			&& ((spec == 'b' && stack->value >= data->avg)
				|| (spec == 'a' && stack->value <= data->avg)))
			stack->g = group_new;
		stack = stack->next;
		--stack_size;
	}
}
