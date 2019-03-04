/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_v_loop_control.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:08:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 21:08:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (vis->buff && vis->pause == 0)
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

int push_swap_v_close(void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	push_swap_exit(vis);
	exit(0);
	return (1);
}
