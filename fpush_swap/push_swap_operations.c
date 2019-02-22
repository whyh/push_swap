/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:36:54 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/22 14:47:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_swap(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
		char **buff, char stack)
{
	if (stack == 'a' || ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value < (*stack_a)->next->next->value))
	{
		push_swap_ss(stack_a);
		ft_strninject(buff, "sa ", -1, -1);
	}
	if (stack == 'b' || (*stack_b && (*stack_b)->value < (*stack_b)->next->value && (*stack_b)->value > (*stack_b)->next->next->value))
	{
		push_swap_ss(stack_b);
		ft_strninject(buff, "sb ", -1, -1);
	}
}

void	push_swap_rotate_rev(t_push_swap_list **stack_a,
		t_push_swap_list **stack_b, char **buff, char stack)
{
//	push_swap_swap(stack_a, stack_b, buff, ' ');
	if (stack == 'a')
	{
		push_swap_rrr(stack_a);
		ft_strninject(buff, "rra ", -1, -1);
	}
	else if (stack == 'b')
	{
		push_swap_rrr(stack_b);
		ft_strninject(buff, "rrb ", -1, -1);
	}
}

void	push_swap_rotate(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
		char **buff, char stack)
{
	if (stack == 'a')
	{
		push_swap_rr(stack_a);
		ft_strninject(buff, "ra ", -1, -1);
	}
	else if (stack == 'b')
	{
		push_swap_rr(stack_b);
		ft_strninject(buff, "rb ", -1, -1);
	}
}

void	push_swap_push(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
		char **buff, char stack)
{
	if (stack == 'a')
	{
		push_swap_pp(stack_a, stack_b);
		ft_strninject(buff, "pb ", -1, -1);
	}
	else if (stack == 'b')
	{
		push_swap_pp(stack_b, stack_a);
		ft_strninject(buff, "pa ", -1, -1);
	}
}
