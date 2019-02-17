/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:36:24 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/17 21:47:20 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap_list	*push_swap_prev(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = stack;
	while (stack_tmp && stack_tmp->next != stack)
		stack_tmp = stack_tmp->next;
	return (stack_tmp);
}

int					push_swap_parse_argv(t_push_swap_list **stack, size_t n,
					char **argv, int *i)
{
	size_t				i2;
	t_push_swap_list	*head;

	head = *stack;
	i2 = 0;
	while (argv[i + 1][i2])
	{
		if (i != 0)
		{
			(*stack)->next = ft_memalloc(sizeof(t_push_swap_list) * n);
			*stack = (*stack)->next;
		}
		if (!ft_strin(DEC, argv[i + 1][i2++]))
		{
			(*stack)->next = head;
			*stack = head;
			return (0);
		}
		(*stack)->value = (int)ft_atoibase(DEC, argv[i + 1]);
	}
}

int					push_swap_parse(t_push_swap_list **stack, size_t n,
					char **argv)
{
	t_push_swap_list	*head;
	size_t				i;

	i = 0;
	*stack = ft_memalloc(sizeof(t_push_swap_list) * n);
	head = *stack;
	while (i < n)
	{

		++i;
	}
	(*stack)->next = head;
	*stack = head;
	return (1);
}

void				push_swap_free(t_push_swap_list **stack)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = push_swap_prev(*stack);
	if (stack_tmp)
		stack_tmp->next = NULL;
	while (*stack)
	{
		stack_tmp = (*stack)->next;
		ft_memdel((void**)stack);
		if (stack_tmp)
			*stack = stack_tmp;
	}
}

int					push_swap_sorted_a(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp;
	t_push_swap_list	*stack_prev;

	stack_prev = stack;
	stack_tmp = stack->next;
	while (stack_tmp != stack)
	{
		if (stack_prev->value > stack_tmp->value)
			return (0);
		stack_prev = stack_prev->next;
		stack_tmp = stack_tmp->next;
	}
	return (1);
}
