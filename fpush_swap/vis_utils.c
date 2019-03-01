/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:40:53 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/28 17:55:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	static_lim(t_push_swap_vis *vis)
{
	t_push_swap_list	*stack;
	size_t				size;

	stack = vis->stack_a;
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

	stack = vis->stack_a;
	vis->data.x0 = vis->min;
	vis->data.x1 = vis->max;
	vis->data.rgb0 = VIS_MUSTARD_YELLOW;
	vis->data.rgb1 = VIS_MAGMA_RED;
	size = push_swap_stack_size(stack);
	while (size > 0)
	{
		vis->data.x = stack->value;
		stack->g = ft_line_gradient(vis->data, 1);
		stack = stack->next;
		--size;
	}
}

void	push_swap_vis_buff(t_push_swap_vis *vis)
{
	char *line;

	while (ft_gnl(0, &line) > 0)
	{
		if (line && !push_swap_valid(line))
		{
			ft_printf("error: ...\n");
			ft_strdel(&line);
			break ;
		}
		ft_strninject(&(vis->buff), line, -1, -1);
		ft_strninject(&(vis->buff), " ", -1, -1);
		ft_strdel(&line);
	}
}

static void static_init_v(t_push_swap_vis *vis, t_vis2d *data,
						  t_push_swap_list *stack_a)
{
	int		trash;
	double	len0;
	double	len1;

	vis->mlx = mlx_init();
	vis->win = mlx_new_window(vis->mlx, PUSH_SWAP_WIN_X, PUSH_SWAP_WIN_Y, "push_swap");
	vis->img = mlx_new_image(vis->mlx, PUSH_SWAP_WIN_X, PUSH_SWAP_WIN_Y);
	vis->img_data = (int*)mlx_get_data_addr(vis->img, &trash, &trash, &trash);
	vis->h = 720 / push_swap_stack_size(stack_a);
	vis->stack_size = push_swap_stack_size(stack_a);
	push_swap_lim(stack_a, vis);
	len0 = push_swap_vis_slope(vis->min, vis->min, vis->max) * PUSH_SWAP_SLOPE;
	len1 = push_swap_vis_slope(vis->min + 1, vis->min, vis->max) * PUSH_SWAP_SLOPE;
	vis->slope = (len1 - len0) / (double)vis->h / 2;
	data->img_data = vis->img_data;
	data->x_max = PUSH_SWAP_WIN_X;
	data->y_max = PUSH_SWAP_WIN_Y;
	push_swap_paint_stack(stack_a, vis);
	vis->buff = NULL;
	vis->status = NULL;
	vis->stack_a = stack_a;
	vis->stack_b = NULL;
	vis->data = *data;
	vis->i = 0;
	vis->start = 1;
	vis->pause = 1;
	push_swap_vis_buff(vis);
}

void push_swap_parse_options(char *arg, t_push_swap_vis *vis, size_t *i)
{
	vis->v = 0;
	vis->t = 0;
	*i = 0;
	if (ft_strncmp("-v", arg, -1) || ft_strncmp(" -v", arg, -1)
	|| ft_strncmp("-v ", arg, -1) || ft_strncmp(" -v ", arg, -1))
	{
		vis->v = 1;
		*i = 1;
	}
	else if (ft_strncmp("-t", arg, -1) || ft_strncmp(" -t", arg, -1)
	|| ft_strncmp("-t ", arg, -1) || ft_strncmp(" -t ", arg, -1))
	{
		vis->t = 1;
		*i = 1;
	}
}

void	push_swap_exit(t_push_swap_vis *vis)
{
	mlx_destroy_image(vis->mlx, vis->img);
	mlx_destroy_window(vis->mlx, vis->win);
	push_swap_free_stack(vis->stack_a);
	if (*(vis->stack_b))
		push_swap_free_stack(vis->stack_b);
}