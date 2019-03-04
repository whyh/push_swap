/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:20:48 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 17:17:26 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap_parse_vt(char *arg, t_push_swap_vis *vis, size_t *i)
{
	vis->v = 0;
	vis->t = 0;
	*i = 0;
	if (ft_strncmp("-v", arg, -1) || ft_strncmp(" -v", arg, -1)
		|| ft_strncmp("-v ", arg, -1) || ft_strncmp(" -v ", arg, -1))
	{
		vis->v = 1;
		*i = 1;
	}
	else if (ft_strncmp("-t", arg, -1) || ft_strncmp(" -t", arg, -1)
			 || ft_strncmp("-t ", arg, -1) || ft_strncmp(" -t ", arg, -1))
	{
		vis->t = 1;
		*i = 1;
	}
}

void	push_swap_exit(t_push_swap_vis *vis)
{
	if (vis->v)
	{
		mlx_destroy_image(vis->mlx, vis->img);
		mlx_destroy_window(vis->mlx, vis->win);
		if (vis->stack_buff && *(vis->stack_buff))
			push_swap_free_stack(vis->stack_buff);
	}
	if (vis->stack_a && *(vis->stack_a))
		push_swap_free_stack(vis->stack_a);
	if (vis->stack_b && *(vis->stack_b))
		push_swap_free_stack(vis->stack_b);
}
