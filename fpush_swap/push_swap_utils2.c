/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:39:47 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/05 15:55:06 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	static_opt_next(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp1;
	t_push_swap_list	*stack_tmp2;
	int					r;
	int					rr;

	r = 0;
	stack_tmp1 = stack;
	while (stack_tmp1->value > push_swap_prev(stack_tmp1, 0)->value)
	{
		stack_tmp1 = stack_tmp1->next;
		++r;
	}
	rr = 0;
	stack_tmp2 = stack;
	while (stack_tmp2->value > push_swap_prev(stack_tmp2, 0)->value)
	{
		stack_tmp2 = push_swap_prev(stack_tmp2, 0);
		--rr;
	}
	return ((ft_abs(r) < ft_abs(rr)) ? r : rr);
}

static void	static_opt_statements(t_push_swap_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value
	&& (data->stack_a->value < data->stack_a->next->next->value
	|| (push_swap_stack_size(data->stack_a) == 3
	&& data->stack_a->next->value > data->stack_a->next->next->value)))
		push_swap_swap(data, 'a');
}

int			push_swap_opt(t_push_swap_data *data)
{
	int	n;

	if (push_swap_sorted_a(data->stack_a))
	{
		data->avg = INT_MAX;
		push_swap_group(data, 0, 0, 'a');
		return (0);
	}
	static_opt_statements(data);
	n = static_opt_next(data->stack_a);
	while (data->stack_a->value > push_swap_prev(data->stack_a, 0)->value
	&& n < 0)
	{
		push_swap_rotate_rev(data, 'a');
		++n;
	}
	while (data->stack_a->value > push_swap_prev(data->stack_a, 0)->value
	&& n > 0)
	{
		push_swap_rotate(data, 'a');
		--n;
	}
	return (!push_swap_sorted_a(data->stack_a) ? 1 : 0);
}

void		get_specs(t_push_swap_data data, size_t *loop, size_t *min)
{
	if (data.stack_size <= 250)
	{
		*loop = 2;
		*min = 5;
	}
	else
	{
		*loop = 3;
		*min = 25;
	}
}
