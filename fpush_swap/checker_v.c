/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:23:35 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 20:00:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_v_start(t_push_swap_vis *vis)
{
	vis->status = "init";
	vis->i = 0;
	vis->o = 0;
	vis->pause = 1;
	if (vis->stack_buff)
	{
		push_swap_free_stack(vis->stack_a);
		push_swap_v_stack_cp(*(vis->stack_buff), vis->stack_a);
		push_swap_free_stack(vis->stack_b);
	}
	else
	{
		vis->stack_buff = ft_memalloc(sizeof(t_push_swap_list*));
		push_swap_v_stack_cp(*(vis->stack_a), vis->stack_buff);
	}
}

void		push_swap_v(t_push_swap_vis *vis)
{
	push_swap_v_init(vis);
	push_swap_v_start(vis);
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
