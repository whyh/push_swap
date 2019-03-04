/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:23:35 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 18:30:58 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	static_stack_cp(t_push_swap_list *stack_src,
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

void		push_swap_v_start(t_push_swap_vis *vis)
{
	vis->status = "init";
	vis->i = 0;
	vis->o = 0;
	vis->pause = 1;
	if (vis->stack_buff)
	{
		push_swap_free_stack(vis->stack_a);
		static_stack_cp(*(vis->stack_buff), vis->stack_a);
		push_swap_free_stack(vis->stack_b);
	}
	else
	{
		vis->stack_buff = ft_memalloc(sizeof(t_push_swap_list*));
		static_stack_cp(*(vis->stack_a), vis->stack_buff);
	}
}

void		push_swap_v_draw(t_push_swap_vis *vis)
{
	push_swap_v_draw_bg(vis);
	if (vis->pause)
		push_swap_v_draw_playb(vis);
	else if (!vis->pause)
		push_swap_v_draw_pauseb(vis);
	push_swap_v_draw_stack(vis, 'a');
	push_swap_v_draw_stack(vis, 'b');
	mlx_put_image_to_window(vis->win, vis->win, vis->img, 0, 0);
	if ((!push_swap_sorted_a(*(vis->stack_a)) || (vis->stack_b && *(vis->stack_b))) && ft_strlen(vis->status) == 3)
		mlx_string_put(vis->mlx, vis->win, 735, 250, PUSH_SWAP_RGB2, vis->status);
	else if ((!push_swap_sorted_a(*(vis->stack_a)) || (vis->stack_b && *(vis->stack_b))) && ft_strlen(vis->status) == 2)
		mlx_string_put(vis->mlx, vis->win, 740, 250, PUSH_SWAP_RGB2, vis->status);
	else if (push_swap_sorted_a(*(vis->stack_a)) && (!vis->stack_b || !*(vis->stack_b)))
		mlx_string_put(vis->mlx, vis->win, 725, 250, PUSH_SWAP_RGB2, "sorted");
	if (vis->help)
	{
		mlx_string_put(vis->mlx, vis->win, 15, 250, PUSH_SWAP_RGB1, "press SPACE");
		mlx_string_put(vis->mlx, vis->win, 15, 270, PUSH_SWAP_RGB1, "to start/pause");
		mlx_string_put(vis->mlx, vis->win, 15, 290, PUSH_SWAP_RGB1, "visualisation");
		mlx_string_put(vis->mlx, vis->win, 15, 360, PUSH_SWAP_RGB1, "press R to set");
		mlx_string_put(vis->mlx, vis->win, 15, 380, PUSH_SWAP_RGB1, "stacks to the");
		mlx_string_put(vis->mlx, vis->win, 15, 400, PUSH_SWAP_RGB1, "initial state");
		mlx_string_put(vis->mlx, vis->win, 15, 470, PUSH_SWAP_RGB1, "press C to turn");
		mlx_string_put(vis->mlx, vis->win, 15, 490, PUSH_SWAP_RGB1, "on/off counter");
	}
	else
		mlx_string_put(vis->mlx, vis->win, 1350, 970, PUSH_SWAP_RGB2, "use H for help");
	if (vis->count)
		mlx_string_put(vis->mlx, vis->win, 1430, 6, PUSH_SWAP_RGB2, ft_itoabase(DEC, vis->o));
	mlx_string_put(vis->mlx, vis->win, 390, 100, PUSH_SWAP_RGB2, "STACK A");
	mlx_string_put(vis->mlx, vis->win, 1040, 100, PUSH_SWAP_RGB2, "STACK B");
}

void		push_swap_v(t_push_swap_vis *vis)
{
	push_swap_v_init(vis);
	push_swap_v_draw(vis);
	mlx_hook(vis->win, 5, 0, &push_swap_v_mouse_release, (void*)vis);
	mlx_hook(vis->win, 4, 0, &push_swap_v_mouse_press, (void*)vis);
	mlx_hook(vis->win, 6, 0, &push_swap_v_mouse_move, (void*)vis);
	mlx_hook(vis->win, 2, 0, &push_swap_v_key_press, (void*)vis);
	mlx_hook(vis->win, 3, 0, &push_swap_v_key_release, (void*)vis);
	mlx_hook(vis->win, 17, 0, &push_swap_v_close, (void*)vis);
	mlx_loop_hook(vis->mlx, &push_swap_v_loop, (void*)vis);
	mlx_loop(vis->mlx);
}
