/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:19:44 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 18:49:40 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	static_simplify(t_push_swap_vis *vis)
{
	size_t				i;
	int 				min;
	int					min_prev;
	t_push_swap_list	*stack;
	t_push_swap_list	*stack_save;

	stack = *(vis->stack_a);
	min_prev = INT_MIN;
	min = vis->min;
	stack_save = NULL;
	while (min == vis->min || stack_save)
	{
		i = 0;
		while (i++ < vis->size)
		{
			if (stack->value < min && stack->value > min_prev)
				min = stack->value;
			stack = stack->next;
		}
		i = 0;
		stack_save = NULL;
		while (i++ < vis->size)
		{
			if (stack->value > min
			&& (!stack_save || stack->value <= stack_save->value))
				stack_save = stack;
			stack = stack->next;
		}
		if (stack_save)
			stack_save->value = min + 1;
		min_prev = min;
		++min;
	}
}

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

static void	static_paint(t_push_swap_vis *vis)
{
	t_push_swap_list	*stack;
	size_t				size;

	stack = *(vis->stack_a);
	vis->data.x0 = vis->min;
	vis->data.x1 = vis->max;
	vis->data.rgb0 = PUSH_SWAP_RGB1;
	vis->data.rgb1 = PUSH_SWAP_RGB2;
	size = push_swap_stack_size(stack);
	while (size > 0)
	{
		vis->data.x = stack->value;
		stack->g = ft_line_gradient(vis->data, 1);
		stack = stack->next;
		--size;
	}
}

static void	static_buff(t_push_swap_vis *vis)
{
	char	*line;

	vis->buff = NULL;
	while (ft_gnl(0, &line) > 0)
	{
		if (line && !push_swap_valid(line))
		{
			ft_printf("error: ...\n");
			ft_strdel(&line);
			push_swap_exit(vis);
			exit(0);
		}
		ft_strninject(&(vis->buff), line, -1, -1);
		ft_strninject(&(vis->buff), " ", -1, -1);
		ft_strdel(&line);
	}
}

void	push_swap_v_init(t_push_swap_vis *vis)
{
	int		trash;
	double	width0;
	double	width1;

	vis->mlx = mlx_init();
	vis->win = mlx_new_window(
			vis->mlx, PUSH_SWAP_WIN_X, PUSH_SWAP_WIN_Y, "push_swap");
	vis->img = mlx_new_image(vis->mlx, PUSH_SWAP_WIN_X, PUSH_SWAP_WIN_Y);
	vis->img_data = (int*)mlx_get_data_addr(vis->img, &trash, &trash, &trash);
	vis->h = (D)PUSH_SWAP_STACK_H / (D)push_swap_stack_size(*(vis->stack_a));
	vis->size = push_swap_stack_size(*(vis->stack_a));
	vis->stack_buff = NULL;
	static_lim(vis);
	static_simplify(vis);
	static_lim(vis);
	width0 = push_swap_v_slope(vis->min, vis->min, vis->max) * PUSH_SWAP_SLOPE;
	width1 = push_swap_v_slope(vis->min + 1, vis->min, vis->max + 1)
			* PUSH_SWAP_SLOPE;
	vis->slope = (width1 - width0) / vis->h / 2;
	vis->data.img_data = vis->img_data;
	vis->data.x_max = PUSH_SWAP_WIN_X;
	vis->data.y_max = PUSH_SWAP_WIN_Y;
	static_paint(vis);
	static_buff(vis);
	vis->mc = 0;
	vis->mb = 0;
	vis->ma = 0;
	vis->count = 0;
	push_swap_v_start(vis);
}
