/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:40:53 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 20:59:09 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	push_swap_v_slope(int value, int min, int max)
{
	double	pos;
	double	slope;
	double	dist;

	dist = max - min;
	pos = value - min;
	if (dist == 0)
		slope = 1.0;
	else
		slope = pos / dist;
	return (slope);
}

void	push_swap_v_paint(t_push_swap_vis *vis)
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

void	push_swap_v_buff(t_push_swap_vis *vis)
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

void	push_swap_v_stack_cp(t_push_swap_list *stack_src,
		t_push_swap_list **stack_dst)
{
	t_push_swap_list	*head;
	t_push_swap_list	*stack;
	size_t				size;

	stack = ft_memalloc(sizeof(t_push_swap_list));
	stack->value = stack_src->value;
	stack->g = stack_src->g;
	head = stack;
	size = push_swap_stack_size(stack_src);
	while (size > 1)
	{
		stack_src = stack_src->next;
		stack->next = ft_memalloc(sizeof(t_push_swap_list));
		stack = stack->next;
		stack->value = stack_src->value;
		stack->g = stack_src->g;
		--size;
	}
	stack->next = head;
	*stack_dst = head;
}
