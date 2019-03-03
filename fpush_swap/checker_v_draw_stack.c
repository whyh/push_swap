/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_draw_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:47:36 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 22:52:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	static_init(t_push_swap_vis *vis, char spec, int *padd,
			t_push_swap_list **stack)
{
	vis->data.y0 = PUSH_SWAP_STACK_Y;
	vis->data.y1 = PUSH_SWAP_STACK_Y;
	if (spec == 'a')
	{
		vis->data.x0 = PUSH_SWAP_STACK_A_X;
		vis->data.x1 = PUSH_SWAP_STACK_A_X + PUSH_SWAP_WIDTH;
		vis->size = push_swap_stack_size(*(vis->stack_a));
		*padd = PUSH_SWAP_STACK_A_X;
		*stack = *(vis->stack_a);
	}
	else if (spec == 'b')
	{
		vis->data.x0 = PUSH_SWAP_STACK_B_X;
		vis->data.x1 = PUSH_SWAP_STACK_B_X + PUSH_SWAP_WIDTH;
		vis->size = push_swap_stack_size(*(vis->stack_b));
		*padd = PUSH_SWAP_STACK_B_X;
		*stack = *(vis->stack_b);
	}

}

void	push_swap_v_draw_stack(t_push_swap_vis *vis, char spec)
{
	t_push_swap_list	*stack;
	double				width;
	int					padd;
	size_t				i;

	static_init(vis, spec, &padd, &stack);
	while (vis->size--)
	{
		i = 0;
		vis->data.rgb0 = stack->g;
		vis->data.rgb1 = stack->g;
		width = push_swap_v_slope(stack->value, vis->min, vis->max + 1)
		* PUSH_SWAP_SLOPE + PUSH_SWAP_WIDTH - PUSH_SWAP_SLOPE;
		vis->data.x0 = padd + ((PUSH_SWAP_WIDTH - width) / 2.0);
		vis->data.x1 = padd + width + ((PUSH_SWAP_WIDTH - width) / 2.0);
		while (i++ < vis->h)
		{
			vis->data.x0 -= vis->slope;
			vis->data.x1 += vis->slope;
			ft_wu_line(vis->data);
			vis->data.y0++;
			vis->data.y1++;
		}
		stack = stack->next;
	}
}
