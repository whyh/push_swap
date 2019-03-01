/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:23:35 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/28 17:55:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"





static void	static_compose_v(t_push_swap_vis *vis, t_vis2d data,
			t_push_swap_list *stack_a, t_push_swap_list *stack_b)
{
	push_swap_vis_bg(vis);
	if (vis->start)
	{
		push_swap_vis_playb(vis);
		vis->start = 0;
	}
	push_swap_vis_stack(vis, data, stack_a, 300);
	push_swap_vis_stack(vis, data, stack_b, 950);
	mlx_put_image_to_window(vis->win, vis->win, vis->img, 0, 0);
}

int static_key_release(int keycode, void *param)
{
	t_push_swap_vis *vis;

	vis = param;
	if (keycode == 49 && vis->pause == 1)
		vis->pause = 0;
	else if (keycode == 49 && vis->pause == 0)
			vis->pause = 1;
	else if (keycode == 15)
	{
		static_init_v(vis, &(vis->data), vis->stack_a);
		static_compose_v(vis, vis->data, vis->stack_a, vis->stack_b);
	}
	return (1);
}

int static_key_press(int keycode, void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	if (keycode == 53 || keycode == 17)
	{
		push_swap_exit(*vis, &(vis->stack_a), &(vis->stack_b));
		exit(0);
	}
	return (1);
}

int static_close(void *param)
{
	t_push_swap_vis	*vis;

	vis = param;
	push_swap_exit(*vis, &(vis->stack_a), &(vis->stack_b));
	exit(0);
	return (1);
}

int static_draw(void *param)
{
	char	*tmp;
	long long n;
	t_push_swap_vis *vis;

	vis = param;
	if (vis->buff[vis->i] && vis->pause == 0)
	{
		n = (int)ft_strchr_i(&(vis->buff[vis->i]), ' ');
		tmp = ft_strndup(&(vis->buff[vis->i]), n);
		push_swap_exec(&(vis->stack_a), &(vis->stack_b), tmp, vis);
		static_compose_v(vis, vis->data, vis->stack_a, vis->stack_b);
		ft_strdel(&tmp);
		vis->i += n + 1;
	}
	return (1);
}



void	push_swap_v(t_push_swap_vis *vis, t_push_swap_list *stack_a)
{
	t_vis2d				data;
	t_push_swap_list	*stack_b;

	if (push_swap_sorted_a(stack_a))
		return ;
	stack_b = NULL;
	static_init_v(vis, &data, stack_a);
    static_compose_v(vis, data, stack_a, stack_b);
	mlx_hook(vis->win, 2, 0, &static_key_press, (void*)vis);
	mlx_hook(vis->win, 3, 0, &static_key_release, (void*)vis);
	mlx_hook(vis->win, 17, 0, &static_close, (void*)vis);
	mlx_loop_hook(vis->mlx, &static_draw, (void*)vis);
	mlx_loop(vis->mlx);
}

void	push_swap_t(t_push_swap_list *stack_a, t_push_swap_list *stack_b,
		char *status)
{
	size_t	size;

	ft_printf("status after [magenta[bold%s~]\n", status);
	ft_printf("[green stack A:~]");
	if (!(size = push_swap_stack_size(stack_a)))
		ft_printf("[cyan empty~]");
	while (size)
	{
		ft_printf(" [cyan%d~]", stack_a->value);
		stack_a = stack_a->next;
		--size;
	}
	ft_printf("\n[green stack B:~]");
	if (!(size = push_swap_stack_size(stack_b)))
		ft_printf("[cyan empty~]");
	while (size)
	{
		ft_printf(" [cyan%d~]", stack_b->value);
		stack_b = stack_b->next;
		--size;
	}
	ft_printf("\n");
}
