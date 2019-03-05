/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:52:37 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/05 16:49:08 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap_exec2(t_push_swap_vis *vis, char *buff)
{
	if (ft_strncmp(buff, "rrr", -1))
	{
		if (*(vis->stack_a))
			push_swap_rrr(vis->stack_a);
		if (*(vis->stack_b))
			push_swap_rrr(vis->stack_b);
	}
	else if (ft_strncmp(buff, "ss", -1))
	{
		if (*(vis->stack_a))
			push_swap_ss(vis->stack_a);
		if (*(vis->stack_b))
			push_swap_ss(vis->stack_b);
	}
	else if (ft_strncmp(buff, "rr", -1))
	{
		if (*(vis->stack_a))
			push_swap_rr(vis->stack_a);
		if (*(vis->stack_b))
			push_swap_rr(vis->stack_b);
	}
}

void		push_swap_exec(t_push_swap_vis *vis, char *buff)
{
	if (!buff)
		return ;
	if (ft_strncmp(buff, "rra", -1) && *(vis->stack_a))
		push_swap_rrr(vis->stack_a);
	else if (ft_strncmp(buff, "rrb", -1) && *(vis->stack_b))
		push_swap_rrr(vis->stack_b);
	else if (ft_strncmp(buff, "sa", -1) && *(vis->stack_a))
		push_swap_ss(vis->stack_a);
	else if (ft_strncmp(buff, "sb", -1) && *(vis->stack_b))
		push_swap_ss(vis->stack_b);
	else if (ft_strncmp(buff, "ra", -1) && *(vis->stack_a))
		push_swap_rr(vis->stack_a);
	else if (ft_strncmp(buff, "rb", -1) && *(vis->stack_b))
		push_swap_rr(vis->stack_b);
	else if (ft_strncmp(buff, "pa", -1) && *(vis->stack_b))
		push_swap_pp(vis->stack_b, vis->stack_a);
	else if (ft_strncmp(buff, "pb", -1) && *(vis->stack_a))
		push_swap_pp(vis->stack_a, vis->stack_b);
	else
		push_swap_exec2(vis, buff);
	if (vis->t)
		push_swap_t(*(vis->stack_a), *(vis->stack_b), buff);
}

int			push_swap_valid(char *buff)
{
	if (ft_strncmp(buff, "rra", -1) || ft_strncmp(buff, "rrb", -1)
	|| ft_strncmp(buff, "sa", -1) || ft_strncmp(buff, "sb", -1)
	|| ft_strncmp(buff, "ra", -1) || ft_strncmp(buff, "rb", -1)
	|| ft_strncmp(buff, "pa", -1) || ft_strncmp(buff, "pb", -1)
	|| ft_strncmp(buff, "ss", -1) || ft_strncmp(buff, "rr", -1)
	|| ft_strncmp(buff, "rrr", -1))
		return (1);
	return (0);
}

static void	push_swap_checker(t_push_swap_vis *vis)
{
	char	*buff;

	if (vis->t)
		push_swap_t(*(vis->stack_a), *(vis->stack_b), "init");
	while (ft_gnl(0, &buff) > 0)
	{
		if (buff && !push_swap_valid(buff))
		{
			ft_printf("[redError: invalid instruction\n");
			ft_strdel(&buff);
			break ;
		}
		push_swap_exec(vis, buff);
		ft_strdel(&buff);
	}
	if (!push_swap_sorted_a(*(vis->stack_a)) || *(vis->stack_b))
		ft_printf("[redKO~]\n");
	else
		ft_printf("[greenOK~]\n");
	push_swap_exit(vis);
}

int			main(int argc, char **argv)
{
	t_push_swap_vis		vis;
	t_push_swap_list	*stack_b;
	size_t				i;

	if (argc == 1 && ft_printf("[redError: no arguments received\n"))
	{
		ft_printf(
		"[greenUsage:~] ./push_swap \"1 3 2\" | ./checker -v \"1 3 2\"\n");
		return (0);
	}
	push_swap_parse_vt(argv[1], &vis, &i);
	if (!push_swap_parse(vis.stack_a, (size_t)(argc - 1), argv, 1 + i))
	{
		push_swap_free_stack(vis.stack_a);
		ft_printf(
		"[greenUsage:~] ./push_swap \"1 3 2\" | ./checker -v \"1 3 2\"\n");
		return (0);
	}
	stack_b = NULL;
	vis.stack_b = &stack_b;
	if (vis.v && *(vis.stack_a) && push_swap_stack_size(*(vis.stack_a)) <= 800)
		push_swap_v(&vis);
	else
		push_swap_checker(&vis);
	return (1);
}
