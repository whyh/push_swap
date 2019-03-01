/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_draw_bg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:45:29 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/28 17:45:29 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap_vis_bg(t_push_swap_vis *vis)
{
	size_t	i;

	i = PUSH_SWAP_WIN_X * PUSH_SWAP_WIN_Y;
	while (i > 0)
	{
		vis->img_data[i] = VIS_BG_GREY;
		--i;
	}
}

void		push_swap_vis_playb(t_push_swap_vis *vis)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < PUSH_SWAP_WIN_Y)
	{
		if (y == 500 || y == 450 || y == 550 || x == 750 || x == 700 || x == 800
			|| y == 150 || y == 110 || y == 900 || y == 180 || x == 950 || x == 1200
			|| x == 300 || x == 550)
			vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_WHITE;
		if (y == 150 && x >= 310 && x <= 315)
			vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_MAGMA_RED;
		++x;
		if (x > PUSH_SWAP_WIN_X)
		{
			x = 0;
			++y;
		}
	}
	x = 0;
	y = 0;
	while (y < PUSH_SWAP_WIN_Y)
	{
		if (x > 700 && x < 800 && y > 350 && y < 450)
			vis->img_data[x + (y * PUSH_SWAP_WIN_X)] = VIS_BG_GREY;
		++x;
		if (x > PUSH_SWAP_WIN_X)
		{
			x = 0;
			++y;
		}
	}
}