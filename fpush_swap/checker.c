/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:52:37 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/18 16:03:11 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_exec2(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
		char *line)
{
	if (ft_strncmp(line, "rrr", -1))
	{
		push_swap_rrr(stack_a);
		push_swap_rrr(stack_b);
	}
	else if (ft_strncmp(line, "ss", -1))
	{
		push_swap_ss(stack_a);
		push_swap_ss(stack_b);
	}
	else if (ft_strncmp(line, "rr", -1))
	{
		push_swap_rr(stack_a);
		push_swap_rr(stack_b);
	}
}

void	push_swap_exec(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
		char *line)
{
	if (ft_strncmp(line, "rra", -1))
		push_swap_rrr(stack_a);
	else if (ft_strncmp(line, "rrb", -1))
		push_swap_rrr(stack_b);
	else if (ft_strncmp(line, "sa", -1))
		push_swap_ss(stack_a);
	else if (ft_strncmp(line, "sb", -1))
		push_swap_ss(stack_b);
	else if (ft_strncmp(line, "ra", -1))
		push_swap_rr(stack_a);
	else if (ft_strncmp(line, "rb", -1))
		push_swap_rr(stack_b);
	else if (ft_strncmp(line, "pa", -1))
		push_swap_pp(stack_b, stack_a);
	else if (ft_strncmp(line, "pb", -1))
		push_swap_pp(stack_a, stack_b);
	else
		push_swap_exec2(stack_a, stack_b, line);
}

static int	push_swap_valid(char *line)
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

static void	push_swap_checker(t_push_swap_list **stack_a)
{
	t_push_swap_list	*stack_b;
	char				*line;

	stack_b = NULL;
	while (ft_gnl(0, &line) > 0)
	{
		if (!push_swap_valid(line))
		{
			ft_printf("error: ...\n");
			ft_strdel(&line);
			break ;
		}
		push_swap_exec(stack_a, &stack_b, line);
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

	if (argc < 2)
	{
		ft_printf("error: invalid argument\n");
		ft_printf("usage: ./push_swap \"1 3 2 4 5 7 6 8 0 9\"\n");
		return (0);
	}
	if (!push_swap_parse(&stack, (size_t)(argc - 1), argv))
	{
		push_swap_free(&stack);
		ft_printf("error: invalid parameter\n");
		ft_printf("usage: ./push_swap \"1 3 2 4 5 7 6 8 0 9\"\n");
		return (0);
	}
	push_swap_checker(&stack);
	push_swap_free(&stack);
	return (1);
}