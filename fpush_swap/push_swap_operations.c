/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:36:54 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 22:20:12 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_swap(t_push_swap_data *data, char stack)
{
	if (stack == 'a'
	|| (data->stack_a->value > data->stack_a->next->value
	&& data->stack_a->value < data->stack_a->next->next->value))
	{
		push_swap_ss(&(data->stack_a));
		ft_strninject(&(data->buff), "sa ", -1, -1);
	}
	if (stack == 'b'
	|| (data->stack_b && data->stack_b->value < data->stack_b->next->value
	&& (data->stack_b->value > data->stack_b->next->next->value
	|| data->stack_b->next->next == data->stack_b)))
	{
		push_swap_ss(&(data->stack_b));
		ft_strninject(&(data->buff), "sb ", -1, -1);
	}
}

void	push_swap_rotate_rev(t_push_swap_data *data, char stack)
{
	if (stack == 'a')
	{
		push_swap_rrr(&(data->stack_a));
		ft_strninject(&(data->buff), "rra ", -1, -1);
	}
	if (stack == 'b'
	|| (data->stack_b && push_swap_prev(data->stack_b, data->group)->value
	> data->stack_b->value))
	{
		push_swap_rrr(&(data->stack_b));
		ft_strninject(&(data->buff), "rrb ", -1, -1);
	}
}

void	push_swap_rotate(t_push_swap_data *data, char stack)
{
	if (stack == 'a'
	|| (data->stack_next && data->stack_next->value > data->stack_a->value))
	{
		push_swap_rr(&(data->stack_a));
		ft_strninject(&(data->buff), "ra ", -1, -1);
	}
	if (stack == 'b'
	|| (data->stack_b && data->stack_next
	&& data->stack_next->value < data->stack_b->value
	&& data->stack_next->value > data->stack_b->next->value))
	{
		push_swap_rr(&(data->stack_b));
		ft_strninject(&(data->buff), "rb ", -1, -1);
	}
}

void	push_swap_push(t_push_swap_data *data, char stack)
{
	if (stack == 'a')
	{
		push_swap_pp(&(data->stack_a), &(data->stack_b));
		ft_strninject(&(data->buff), "pb ", -1, -1);
	}
	else if (stack == 'b')
	{
		push_swap_pp(&(data->stack_b), &(data->stack_a));
		ft_strninject(&(data->buff), "pa ", -1, -1);
	}
}
