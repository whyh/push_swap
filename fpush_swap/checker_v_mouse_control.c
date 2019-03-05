/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_mouse_control.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:00:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 22:54:08 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_v_mouse_press(int button, int x, int y, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	if (button == 1 && x >= 700 && x <= 800 && y >= 470 && y <= 580)
	{
		vis->mpc = 1;
		if (!vis->buff || !vis->buff[vis->i])
			push_swap_v_start(vis);
		else if (vis->pause == 0)
			vis->pause = 1;
		else if (vis->pause == 1)
			vis->pause = 0;
	}
	push_swap_v_draw(vis);
	return (1);
}

int	push_swap_v_mouse_release(int button, int x, int y, void *param)
{
	t_push_swap_vis	*vis;

	(void)x;
	(void)y;
	vis = param;
	if (button == 1)
		vis->mpc = 0;
	push_swap_v_draw(vis);
	return (1);
}

int	push_swap_v_mouse_move(int x, int y, void *param)
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
