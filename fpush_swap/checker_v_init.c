/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:19:44 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 20:39:18 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	static_lim(t_push_swap_vis *vis)
{
	t_push_swap_list	*stack;
	size_t				size;

	stack = *(vis->stack_a);
	vis->max = stack->value;
	vis->min = stack->value;
	size = push_swap_stack_size(stack);
	while (size > 0)
	{
		stack = stack->next;
		if (stack->value > vis->max)
			vis->max = stack->value;
		if (stack->value < vis->min)
			vis->min = stack->value;
		--size;
	}
}

static void	static_simplify_min(t_push_swap_vis *vis, int *min, int *min_prev,
			t_push_swap_list *stack)
{
	size_t	i;

	i = 0;
	while (i < vis->init_size)
	{
		if (stack->value < *min && stack->value > *min_prev)
			*min = stack->value;
		stack = stack->next;
		++i;
	}
	*min_prev = *min;
}

static void	static_simplify(t_push_swap_vis *vis, t_push_swap_list	*stack)
{
	int 				min;
	size_t				i;
	int					min_prev;
	t_push_swap_list	*stack_save;

	static_lim(vis);
	min_prev = INT_MIN;
	min = vis->min;
	stack_save = NULL;
	while (min == vis->min || stack_save)
	{
		static_simplify_min(vis, &min, &min_prev, stack);
		stack_save = NULL;
		i = 0;
		while (i++ < vis->init_size)
		{
			if (stack->value > min
				&& (!stack_save || stack->value <= stack_save->value))
				stack_save = stack;
			stack = stack->next;
		}
		if (stack_save)
			stack_save->value = min + 1;
		++min;
	}
}

static void	static_base_slope(t_push_swap_vis *vis)
{
	double	width0;
	double	width1;

	width0 = push_swap_v_slope(vis->min, vis->min, vis->max);
	width1 = push_swap_v_slope(vis->min + 1, vis->min, vis->max + 1);
	vis->slope = (width1 - width0) * PUSH_SWAP_SLOPE / vis->h / 2;
}

void	push_swap_v_init(t_push_swap_vis *vis)
{
	int	trash;

	push_swap_v_buff(vis);
	vis->mlx = mlx_init();
	vis->win = mlx_new_window(
			vis->mlx, PUSH_SWAP_WIN_X, PUSH_SWAP_WIN_Y, "push_swap");
	vis->img = mlx_new_image(vis->mlx, PUSH_SWAP_WIN_X, PUSH_SWAP_WIN_Y);
	vis->img_data = (int*)mlx_get_data_addr(vis->img, &trash, &trash, &trash);
	vis->data.img_data = vis->img_data;
	vis->data.x_max = PUSH_SWAP_WIN_X;
	vis->data.y_max = PUSH_SWAP_WIN_Y;
	vis->h = (D)PUSH_SWAP_STACK_H / (D)push_swap_stack_size(*(vis->stack_a));
	vis->init_size = push_swap_stack_size(*(vis->stack_a));
	vis->stack_buff = NULL;
	static_simplify(vis, *(vis->stack_a));
	static_lim(vis);
	static_base_slope(vis);
	push_swap_v_paint(vis);
	vis->mc = 0;
	vis->mb = 0;
	vis->ma = 0;
	vis->count = 0;
}
