/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:35:38 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/17 21:47:20 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap_sort(t_push_swap_list **stack_a,
			t_push_swap_list **stack_b, t_push_swap_sort *sort, char stack)
{
	int		next;

	while ((stack == 'a' && !push_swap_sorted_a(*stack_a))
	|| (stack == 'b' && !push_swap_sorted_b(*stack_b, sort->group)))
	{
		push_swap_swap(stack_a, stack_b, &(sort->buff));
		if (stack == 'a')
			next = push_swap_next(*stack_a, sort->group);
		else
			next = push_swap_next(*stack_b, sort->group);
		if (next > 0)
			push_swap_rotate(stack_a, stack_b, &(sort->buff), stack);
		else if (next < 0)
			push_swap_rotate_rev(stack_a, stack_b, &(sort->buff), stack);
		if (!(stack == 'a' && push_swap_sorted_a(*stack_a)))
			push_swap_push(stack_a, stack_b, &(sort->buff), stack);
	}
}

static void	push_swap_group(t_push_swap_list *stack, size_t group, int avg)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = stack;
	if (stack_tmp->value <= avg)
		stack_tmp->group = group;
	else
		stack_tmp->group = 0;
	stack_tmp = stack_tmp->next;
	while (stack_tmp != stack)
	{
		if (stack_tmp->value <= avg)
			stack_tmp->group = group;
		else
			stack_tmp->group = 0;
		stack_tmp = stack_tmp->next;
	}
}

static void	push_swap_outp(char **buff)
{
	ft_strfrepl(buff, "sa sb ", "ss ", -1);
	ft_strfrepl(buff, "sb sa ", "ss ", -1);
	ft_strfrepl(buff, "ra rb ", "rr ", -1);
	ft_strfrepl(buff, "rb ra ", "rr ", -1);
	ft_strfrepl(buff, "rra rrb ", "rrr ", -1);
	ft_strfrepl(buff, "rrb rra ", "rrr ", -1);
	ft_strfrepl(buff, " ", "\n", -1);
	if (*buff == NULL)
		*buff = ft_strnew(0);
	ft_printf("%s", *buff);
	ft_strdel(buff);
}

static void	push_swap(t_push_swap_list *stack_a)
{
	t_push_swap_list	*stack_b;
	t_push_swap_sort	sort;
	int					avg;

	sort.group = 0;
	stack_b = NULL;
	sort.buff = NULL;
	while (!push_swap_sorted_a(stack_a) || stack_b != NULL)
	{
		while (!push_swap_sorted_a(stack_a))
		{
			sort.group++;
			avg = push_swap_avg(stack_a);
			push_swap_group(stack_a, sort.group, avg);
			push_swap_sort(&stack_a, &stack_b, &sort, 'a');
		}
		if (stack_b != NULL)
		{
			push_swap_sort(&stack_a, &stack_b, &sort, 'b');
			sort.group--;
		}
	}
	push_swap_outp(&(sort.buff));
}

int			main(int argc, char **argv)
{
	t_push_swap_list	*stack;

	if (argc < 2)
	{
		ft_printf("error: ...\n");
		ft_printf("usage: ...\n");
		return (0);
	}
	if (!push_swap_parse(&stack, (size_t)(argc - 1), argv))
	{
		push_swap_free(&stack);
		ft_printf("error: ...\n");
		ft_printf("usage: ...\n");
		return (0);
	}
	push_swap(stack);
	push_swap_free(&stack);
	return (1);
}
