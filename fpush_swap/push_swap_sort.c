/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:35:18 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/05 15:58:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	static_shift_a(t_push_swap_data *data)
{
	push_swap_next(*data, data->stack_b, &(data->stack_next_next),
	data->stack_next);
	while (data->stack_next->value > data->stack_a->value
	&& (data->stack_next->value > data->stack_a->next->value))
	{
		push_swap_rotate(data, 'a');
		data->i++;
	}
	while (push_swap_prev(data->stack_a, 0)->value < data->stack_a->value
	&& push_swap_prev(data->stack_a, 0)->value > data->stack_b->value)
		push_swap_rotate_rev(data, 'a');
}

void		push_swap_sort(t_push_swap_data *data, char stack)
{
	if (stack == 'a')
		data->i = 0;
	while ((stack == 'a' && (!push_swap_sorted_a(data->stack_a)
	&& !push_swap_sorted(data->stack_a, data->group)))
	|| (stack == 'b' && !push_swap_sorted(data->stack_b, data->group)))
	{
		push_swap_swap(data, ' ');
		push_swap_get_next(data, stack);
		if (!(stack == 'a' && push_swap_sorted_a(data->stack_a)))
		{
			if (stack == 'b')
				static_shift_a(data);
			push_swap_push(data, stack);
			if (stack == 'b'
			&& data->stack_a->value > data->stack_a->next->value)
				push_swap_swap(data, 'a');
		}
	}
}
