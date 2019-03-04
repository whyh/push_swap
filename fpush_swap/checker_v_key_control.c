/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_key_control.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:04:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 21:04:00 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap_v_key_release(int keycode, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	vis->mpc = 0;
	vis->mc = 0;
	if (keycode == 49 && push_swap_sorted_a(*(vis->stack_a))
		&& (!vis->stack_b || !*(vis->stack_b)))
		push_swap_v_start(vis);
	else if (keycode == 49 && vis->pause == 1)
		vis->pause = 0;
	else if (keycode == 49 && vis->pause == 0)
		vis->pause = 1;
	else if (keycode == 15)
		push_swap_v_start(vis);
	else if (keycode == 4 && vis->help == 1)
		vis->help = 0;
	else if (keycode == 8 && vis->count == 0)
		vis->count = 1;
	else if (keycode == 8 && vis->count == 1)
		vis->count = 0;
	push_swap_v_draw(vis);
	return (1);
}

int push_swap_v_key_press(int keycode, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	if (keycode == 53 || keycode == 17)
	{
		push_swap_exit(vis);
		exit(0);
	}
	else if (keycode == 49)
	{
		vis->mpc = 1;
		push_swap_v_draw(vis);
	}
	else if (keycode == 4 && vis->help == 0)
	{
		vis->help = 1;
		push_swap_v_draw(vis);
	}
	return (1);
}
