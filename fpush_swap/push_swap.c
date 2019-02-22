/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:35:38 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/22 15:38:27 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO DEL
//void	print(t_push_swap_list *stack_a, t_push_swap_list *stack_b)
//{
//	t_push_swap_list *t_tmp;
//
//	(void)stack_b;
//	ft_printf("\n\n\n\n\n\n\n\nstack a :\n%d ", stack_a->value);
//	t_tmp = stack_a->next;
//	while (t_tmp != stack_a)
//	{
//		ft_printf("%d ", t_tmp->value);
//		t_tmp = t_tmp->next;
//	}
//}

static void	push_swap_group(t_push_swap_list *stack, size_t group, int avg, size_t base_group, size_t spec)
{
	t_push_swap_list	*stack_tmp;

	stack_tmp = stack;
	if ((base_group == 0 || stack_tmp->group == base_group)
	&& ((spec == 'a' && stack_tmp->value <= avg) || (spec == 'b' && stack_tmp->value >= avg)))
		stack_tmp->group = group;
	stack_tmp = stack_tmp->next;
	while (stack_tmp != stack)
	{
		if ((base_group == 0 || stack_tmp->group == base_group)
			&& ((spec == 'a' && stack_tmp->value <= avg) || (spec == 'b' && stack_tmp->value >= avg)))
			stack_tmp->group = group;
		stack_tmp = stack_tmp->next;
	}
}

static void	push_swap_sort(t_push_swap_list **stack_a,
			t_push_swap_list **stack_b, t_push_swap_data *sort, char stack)
{
	int	next;

	while ((stack == 'a' && (!push_swap_sorted_a(*stack_a)
	&& !push_swap_sorted(*stack_a, sort->group)))
	|| (stack == 'b' && !push_swap_sorted(*stack_b, sort->group)))
	{
		push_swap_swap(stack_a, stack_b, &(sort->buff), ' ');
		if (stack == 'a')
			next = push_swap_next(*stack_a, sort->group);
		else
			next = push_swap_next(*stack_b, sort->group);
		while (next > 0)
		{
			push_swap_rotate(stack_a, stack_b, &(sort->buff), stack);
			--next;
		}
		while (next < 0)
		{
			push_swap_rotate_rev(stack_a, stack_b, &(sort->buff), stack);
			++next;
		}
		if (!(stack == 'a' && push_swap_sorted_a(*stack_a)))
		{
			if (stack == 'a' && *stack_b && (*stack_a)->value < (*stack_b)->value && (*stack_a)->value > (*stack_b)->next->value)
			{
				push_swap_rotate(stack_a, stack_b, &(sort->buff), 'b');
				push_swap_push(stack_a, stack_b, &(sort->buff), stack);
				push_swap_rotate_rev(stack_a, stack_b, &(sort->buff), 'b');
			}
			else
				push_swap_push(stack_a, stack_b, &(sort->buff), stack);
		}
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

int	push_swap_opt_next(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp;
	int					r;
	int					rr;

	stack_tmp = stack;
	r = 0;
	while (stack->value > push_swap_prev(stack, 0)->value)
	{
		stack = stack->next;
		++r;
	}
	rr = 0;
	while (stack_tmp->value > push_swap_prev(stack_tmp, 0)->value)
	{
		stack_tmp = push_swap_prev(stack_tmp, 0);
		--rr;
	}
	if (push_swap_sorted_a(stack))
		return ((ft_abs(r) < ft_abs(rr)) ? r : rr);
	return (0);
}

int			push_swap_opt(t_push_swap_list **stack_a, t_push_swap_list **stack_b,
			char **buff)
{
	int	n;

	if (push_swap_sorted_a(*stack_a))
		return (0);
	if ((*stack_a)->value > (*stack_a)->next->value
	&& ((*stack_a)->value < (*stack_a)->next->next->value
	|| ((*stack_a) == (*stack_a)->next->next->next
	&& (*stack_a)->next->value > (*stack_a)->next->next->value)))
		push_swap_swap(stack_a, stack_b, buff, 'a');
	n = push_swap_opt_next(*stack_a);
	while ((*stack_a)->value > push_swap_prev(*stack_a, 0)->value && n < 0)
	{
		push_swap_rotate_rev(stack_a, stack_b, buff, 'a');
		++n;
	}
	while ((*stack_a)->value > push_swap_prev(*stack_a, 0)->value && n > 0)
	{
		push_swap_rotate(stack_a, stack_b, buff, 'a');
		--n;
	}
	return (!push_swap_sorted_a(*stack_a) ? 1 : 0);
}

int push_swap_max_group(t_push_swap_list *stack, int occur, size_t group)
{
	t_push_swap_list	*stack_tmp;

	if (!stack)
		return (0);
	if (stack->group == group)
		--occur;
	stack_tmp = stack->next;
	while (stack_tmp != stack && occur > 0)
	{
		if (stack_tmp->group == group)
			--occur;
		stack_tmp = stack_tmp->next;
	}
	if (occur <= 0)
		return (1);
	return (0);
}

static void	push_swap(t_push_swap_data *data)
{
	int	avg;

	data->group = 0;
	data->stack_b = NULL;
	data->buff = NULL;
	while (!push_swap_sorted_a(data->stack_a) || data->stack_b != NULL)
	{
		while (push_swap_opt(data))
		{
			data->curr_stack = 'a';
			avg = push_swap_avg(data->stack_a, data->group);//of last arrived group to a or 0 on innit
			data->group++;// update counter to mark new group
			push_swap_group(data, avg, 0);
			push_swap_sort(data);
		}
		if (data->stack_b != NULL)
		{
			data->curr_stack = 'b';
			while (!push_swap_max_group(data, 1))
				data->group--;
			if (push_swap_max_group(data, 3))
			{
				avg = push_swap_avg(data->stack_b, data->group);// avg of group in b
				data->group++;// to mark next subgroup in b
				push_swap_group(data, avg, data->group - 1);
			}
			if (push_swap_max_group(stack_b, 3, sort.group))
			{
				avg = push_swap_avg(stack_b, sort.group);// avg of group in b
				sort.group++;// to mark next subgroup in b
				push_swap_group(stack_b, sort.group, avg, sort.group - 1, 'b');
			}
			push_swap_sort(&stack_a, &stack_b, &sort, 'b');//of last arrived group to b
		}
		if (push_swap_sorted_a(stack_a))
			push_swap_group(stack_a, 0, INT_MAX, 0, 'a');
	}
	push_swap_outp(&(data.buff));
}

int			main(int argc, char **argv)
{
	t_push_swap_data	data;

	if (argc < 2)
	{
		ft_printf("error: invalid usage\n");
		ft_printf("usage: ./push_swap \"1 3 2 4 5 7 6 8 0 9\"\n");
		return (0);
	}
	if (!push_swap_parse(&(data.stack_a), (size_t)(argc - 1), argv))
	{
		push_swap_free(&(data.stack_a));
		ft_printf("error: invalid argument\n");
		ft_printf("usage: ./push_swap \"1 3 2 4 5 7 6 8 0 9\"\n");
		return (0);
	}
	push_swap(&data);
	push_swap_free(&(data.stack_a));
	system("leaks push_swap");
	return (1);
}
