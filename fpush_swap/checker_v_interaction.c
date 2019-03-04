/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_interaction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:00:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 18:16:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap_v_key_release(int keycode, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
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
	vis->mpc = 0;
	return (1);
}

int push_swap_v_mouse_press(int button, int x, int y, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	if (button == 1 && x >= 700 && x <= 800 && y >= 470 && y <= 580)
	{
		vis->mpc = 1;
		if (push_swap_sorted_a(*(vis->stack_a))
		&& (!vis->stack_b || !*(vis->stack_b)))
		{
			push_swap_v_start(vis);
			push_swap_v_draw(vis);
		}
		else if (vis->pause == 0)
			vis->pause = 1;
		else if (vis->pause == 1)
			vis->pause = 0;
		push_swap_v_draw(vis);
	}
	return (1);
}

int push_swap_v_mouse_release(int button, int x, int y, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	(void)x;
	(void)y;
	if (button == 1)
	{
		vis->mpc = 0;
		push_swap_v_draw(vis);
	}
	return (1);
}

int push_swap_v_mouse_move(int x, int y, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	if (x >= 700 && x <= 800 && y >= 470 && y <= 580)
		vis->mc = 1;
	else if (x >= PUSH_SWAP_STACK_A_X - PUSH_SWAP_BORDER
	&& x <= PUSH_SWAP_STACK_A_X + PUSH_SWAP_WIDTH + PUSH_SWAP_BORDER
	&& y >= PUSH_SWAP_STACK_Y - PUSH_SWAP_BORDER
	&& y <= PUSH_SWAP_STACK_Y + PUSH_SWAP_STACK_H + PUSH_SWAP_BORDER)
		vis->ma = 1;
	else if (x >= PUSH_SWAP_STACK_B_X - PUSH_SWAP_BORDER
	&& x <= PUSH_SWAP_STACK_B_X + PUSH_SWAP_WIDTH + PUSH_SWAP_BORDER
	&& y >= PUSH_SWAP_STACK_Y - PUSH_SWAP_BORDER
	&& y <= PUSH_SWAP_STACK_Y + PUSH_SWAP_STACK_H + PUSH_SWAP_BORDER)
		vis->mb = 1;
	else
	{
		vis->mc = 0;
		vis->ma = 0;
		vis->mb = 0;
	}
	if (vis->pause == 1)
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

int push_swap_v_close(void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	push_swap_exit(vis);
	exit(0);
	return (1);
}

int push_swap_v_loop(void *param)
{
	t_push_swap_vis	*vis;
	long long		n;

	vis = param;
	if (vis->buff && !vis->buff[vis->i])
	{
		vis->pause = 1;
		push_swap_v_draw(vis);
	}
	else if (vis->pause == 0)
	{
		vis->o++;
		n = (LL)ft_strchr_i(&(vis->buff[vis->i]), ' ');
		vis->status = ft_strndup(&(vis->buff[vis->i]), n);
		push_swap_exec(vis, vis->status);
		push_swap_v_draw(vis);
		ft_strdel(&(vis->status));
		vis->i += n + 1;
	}
	return (1);
}