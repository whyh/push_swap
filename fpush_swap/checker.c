/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:52:37 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/28 17:55:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap_exec2(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
		char *line)
{
	if (ft_strncmp(line, "rrr", -1))
	{
		if (*stack_a)
			push_swap_rrr(stack_a);
		if (*stack_b)
			push_swap_rrr(stack_b);
	}
	else if (ft_strncmp(line, "ss", -1))
	{
		if (*stack_a)
			push_swap_ss(stack_a);
		if (*stack_b)
			push_swap_ss(stack_b);
	}
	else if (ft_strncmp(line, "rr", -1))
	{
		if (*stack_a)
			push_swap_rr(stack_a);
		if (*stack_b)
			push_swap_rr(stack_b);
	}
}

void	push_swap_exec(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
		char *line, t_push_swap_vis *vis)
{
	if (ft_strncmp(line, "rra", -1) && *stack_a)
		push_swap_rrr(stack_a);
	else if (ft_strncmp(line, "rrb", -1) && *stack_b)
		push_swap_rrr(stack_b);
	else if (ft_strncmp(line, "sa", -1) && *stack_a)
		push_swap_ss(stack_a);
	else if (ft_strncmp(line, "sb", -1) && *stack_b)
		push_swap_ss(stack_b);
	else if (ft_strncmp(line, "ra", -1) && *stack_a)
		push_swap_rr(stack_a);
	else if (ft_strncmp(line, "rb", -1) && *stack_b)
		push_swap_rr(stack_b);
	else
	if (ft_strncmp(line, "pa", -1) && *stack_b)
		push_swap_pp(stack_b, stack_a);
	else
	if (ft_strncmp(line, "pb", -1) && *stack_a)
		push_swap_pp(stack_a, stack_b);
	else
		push_swap_exec2(stack_a, stack_b, line);
	if (vis->t)
		push_swap_t(*stack_a, *stack_b, line);
}

int	push_swap_valid(char *line)
{
	if (ft_strncmp(line, "rra", -1) || ft_strncmp(line, "rrb", -1)
	|| ft_strncmp(line, "sa", -1) || ft_strncmp(line, "sb", -1)
	|| ft_strncmp(line, "ra", -1) || ft_strncmp(line, "rb", -1)
	|| ft_strncmp(line, "pa", -1) || ft_strncmp(line, "pb", -1)
	|| ft_strncmp(line, "ss", -1) || ft_strncmp(line, "rr", -1)
	|| ft_strncmp(line, "rrr", -1))
		return (1);
	return (0);
}

static void	push_swap_checker(t_push_swap_list **stack_a, t_push_swap_vis *vis)
{
	t_push_swap_list	*stack_b;
	char				*line;

	stack_b = NULL;
	if (vis->t)
		push_swap_t(*stack_a, stack_b, "init");
	while (ft_gnl(0, &line) > 0)
	{
		if (line && !push_swap_valid(line))
		{
			ft_printf("error: ...\n");
			ft_strdel(&line);
			break ;
		}
		push_swap_exec(stack_a, &stack_b, line, vis);
		ft_strdel(&line);
	}
	if (!push_swap_sorted_a(*stack_a) || stack_b)
		ft_printf("[redKO~]\n");
	else
		ft_printf("[greenOK~]\n");
}

int			main(int argc, char **argv)
{
	t_push_swap_list	*stack;
	t_push_swap_vis		vis;
	size_t				i;

	if (argc < 2)
	{
		ft_printf("error: invalid argument\n");
		ft_printf("usage: ./push_swap \"1 3 2 4 5 7 6 8 0 9\"\n");
		return (0);
	}
	push_swap_parse_options(argv[1], &vis, &i);
	if (!push_swap_parse(&stack, (size_t)(argc - 1), argv, 1 + i))
	{
		push_swap_free_stack(&stack);
		ft_printf("error: invalid parameter\n");
		ft_printf("usage: ./push_swap \"1 3 2 4 5 7 6 8 0 9\"\n");
		return (0);
	}
	if (vis.v)
		push_swap_v(&vis, stack);
	else
		push_swap_checker(&stack, &vis);
	push_swap_exit(vis, &stack, NULL);
	return (1);
}