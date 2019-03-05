/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_draw_bg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:45:29 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 20:08:28 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	static_draw_border(t_push_swap_vis *vis, size_t stack_x, char spec)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < PUSH_SWAP_WIN_Y)
	{
		if (x >= stack_x - PUSH_SWAP_BORDER
		&& x <= stack_x + PUSH_SWAP_WIDTH + PUSH_SWAP_BORDER
		&& y >= PUSH_SWAP_STACK_Y - PUSH_SWAP_BORDER
		&& y <= PUSH_SWAP_STACK_Y + PUSH_SWAP_STACK_H + PUSH_SWAP_BORDER)
		{
			if ((vis->ma == 0 && spec == 'a') || (vis->mb == 0 && spec == 'b'))
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_GREY;
			else
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_BRIGHT_GREY;
		}
		if (x >= stack_x
		&& x <= stack_x + PUSH_SWAP_WIDTH + 1 && y >= PUSH_SWAP_STACK_Y
		&& y <= PUSH_SWAP_STACK_Y + PUSH_SWAP_STACK_H)
			vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_BG_GREY;
		if (++x > PUSH_SWAP_WIN_X && (++y))
			x = 0;
	}
}

static void	static_draw_pauseb(t_push_swap_vis *vis)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < PUSH_SWAP_WIN_Y)
	{
		if (y >= 470 && y <= 580 && ((x >= 700 && x <= 735)
		|| (x <= 800 && x >= 765)))
		{
			if (vis->mc == 0 && vis->mpc == 0)
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_GREY;
			else if (vis->mpc == 1)
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_DARK_GREY;
			else if (vis->mc == 1)
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_BRIGHT_GREY;
		}
		++x;
		if (x > PUSH_SWAP_WIN_X)
		{
			x = 0;
			++y;
		}
	}
}

static void	static_draw_playb(t_push_swap_vis *vis, size_t x, size_t y)
{
	double	i;

	i = 100.0;
	while (y < PUSH_SWAP_WIN_Y)
	{
		if (y >= 470 && y <= 580 && x >= 700 && x + i <= 800)
		{
			if (vis->mc == 0 && vis->mpc == 0)
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_GREY;
			else if (vis->mpc == 1)
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_DARK_GREY;
			else if (vis->mc == 1)
				vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_BRIGHT_GREY;
		}
		++x;
		if (x > PUSH_SWAP_WIN_X)
		{
			if (y >= 470 && y < 525)
				i -= 100.0 / 55.0;
			else if (y > 525 && y <= 580)
				i += 100.0 / 55.0;
			x = 0;
			++y;
		}
	}
}

void		push_swap_v_draw_bg(t_push_swap_vis *vis)
{
	size_t	i;

	i = PUSH_SWAP_WIN_X * PUSH_SWAP_WIN_Y;
	while (i > 0)
	{
		vis->img_data[i] = VIS_BG_GREY;
		--i;
	}
	static_draw_border(vis, PUSH_SWAP_STACK_A_X, 'a');
	static_draw_border(vis, PUSH_SWAP_STACK_B_X, 'b');
	if (vis->pause)
		static_draw_playb(vis, 0, 0);
	else
		static_draw_pauseb(vis);
}
