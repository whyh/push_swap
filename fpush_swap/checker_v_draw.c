/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:00:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 20:00:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	static_draw_h_menu(t_push_swap_vis *vis)
{
	if (vis->help)
	{
		mlx_string_put(
		vis->mlx, vis->win, 15, 250, PUSH_SWAP_RGB1, "press SPACE");
		mlx_string_put(
		vis->mlx, vis->win, 15, 270, PUSH_SWAP_RGB1, "to start/pause");
		mlx_string_put(
		vis->mlx, vis->win, 15, 290, PUSH_SWAP_RGB1, "visualisation");
		mlx_string_put(
		vis->mlx, vis->win, 15, 360, PUSH_SWAP_RGB1, "press R to set");
		mlx_string_put
		(vis->mlx, vis->win, 15, 380, PUSH_SWAP_RGB1, "stacks to the");
		mlx_string_put(
		vis->mlx, vis->win, 15, 400, PUSH_SWAP_RGB1, "initial state");
		mlx_string_put(
		vis->mlx, vis->win, 15, 470, PUSH_SWAP_RGB1, "press C to turn");
		mlx_string_put(
		vis->mlx, vis->win, 15, 490, PUSH_SWAP_RGB1, "on/off counter");
	}
	else
		mlx_string_put(
		vis->mlx, vis->win, 1350, 970, PUSH_SWAP_RGB2, "use H for help");
}

static void	static_draw_interface(t_push_swap_vis *vis)
{
	if (ft_strlen(vis->status) == 3 && (!push_swap_sorted_a(*(vis->stack_a))
	|| (vis->stack_b && *(vis->stack_b))))
		mlx_string_put(
		vis->mlx, vis->win, 735, 250, PUSH_SWAP_RGB2, vis->status);
	else if ((!push_swap_sorted_a(*(vis->stack_a))
	|| (vis->stack_b && *(vis->stack_b))) && ft_strlen(vis->status) == 2)
		mlx_string_put(
		vis->mlx, vis->win, 740, 250, PUSH_SWAP_RGB2, vis->status);
	else if (push_swap_sorted_a(*(vis->stack_a))
	&& (!vis->stack_b || !*(vis->stack_b)))
		mlx_string_put(vis->mlx, vis->win, 725, 250, PUSH_SWAP_RGB2, "sorted");
	if (vis->count)
		mlx_string_put(
		vis->mlx, vis->win, 1430, 6, PUSH_SWAP_RGB2, ft_itoabase(DEC, vis->o));
	mlx_string_put(vis->mlx, vis->win, 390, 100, PUSH_SWAP_RGB2, "STACK A");
	mlx_string_put(vis->mlx, vis->win, 1040, 100, PUSH_SWAP_RGB2, "STACK B");
}

static void	static_compose_pic(t_push_swap_vis *vis)
{
	push_swap_v_draw_bg(vis);
	push_swap_v_draw_stack(vis, 'a');
	push_swap_v_draw_stack(vis, 'b');
	mlx_put_image_to_window(vis->win, vis->win, vis->img, 0, 0);
	static_draw_h_menu(vis);
	static_draw_interface(vis);
}

void		push_swap_v_draw(t_push_swap_vis *vis)
{
	size_t	i;

	if (vis->init_size <= 10)
		i = 4;
	else if (vis->init_size <= 50)
		i = 3;
	else if (vis->init_size <= 100)
		i = 2;
	else
		i = 1;
	while (i-- > 0)
		static_compose_pic(vis);
}