/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:35:38 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/22 21:50:17 by dderevyn         ###   ########.fr       */
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

void	p2(t_push_swap_data *data, char stack)
{
	int	next;

	next = push_swap_next(data, stack);
	while (next > 0)
	{
		push_swap_rotate(data, stack);
		--next;
	}
	while (next < 0)
	{
		push_swap_rotate_rev(data, stack);
		++next;
	}
}

static void	push_swap_sort(t_push_swap_data *data, char stack)
{
	static int i = 0;

	if (stack == 'a')
		i = 0;
	while ((stack == 'a' && (!push_swap_sorted_a(data->stack_a)
	&& !push_swap_sorted(data->stack_a, data->group)))
	|| (stack == 'b' && !push_swap_sorted(data->stack_b, data->group)))
	{
		push_swap_swap(data, ' ');
		p2(data, stack);
		if (!(stack == 'a' && push_swap_sorted_a(data->stack_a)))
		{
			if (stack == 'b')
			{
				push_swap_next_next(data, stack);
				while (data->stack_next->value > data->stack_a->value
				&& (data->stack_next->value > data->stack_a->next->value
				|| (data->stack_next->group == data->group
				&& data->stack_next->value > data->stack_a->value))
				{
					push_swap_rotate(data, 'a');
					++i;
				}
			}
			push_swap_push(data, stack);
			if (stack == 'b' && data->stack_a->value > data->stack_a->next->value)
				push_swap_swap(data, 'a');
			while (stack == 'b' && i > 0)
//			&& data->stack_next->group == data->group
//			&& data->stack_next->value < push_swap_prev(data->stack_a, 0)->value)
			{
				--i;
				push_swap_rotate_rev(data, 'a');
			}
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

int	push_swap_opt_next(t_push_swap_list *stack)//TODO replace with push_swap_next
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

int			push_swap_opt(t_push_swap_data *data)
{
	int	n;

	if (push_swap_sorted_a(data->stack_a))
		return (0);
	if (data->stack_a->value > data->stack_a->next->value
	&& (data->stack_a->value < data->stack_a->next->next->value
	|| (data->stack_a == data->stack_a->next->next->next
	&& data->stack_a->next->value > data->stack_a->next->next->value)))
		push_swap_swap(data, 'a');
	n = push_swap_opt_next(data->stack_a);
	while (data->stack_a->value > push_swap_prev(data->stack_a, 0)->value && n < 0)
	{
		push_swap_rotate_rev(data, 'a');
		++n;
	}
	while (data->stack_a->value > push_swap_prev(data->stack_a, 0)->value && n > 0)
	{
		push_swap_rotate(data, 'a');
		--n;
	}
	return (!push_swap_sorted_a(data->stack_a) ? 1 : 0);
}

int push_swap_max_group(t_push_swap_list *stack, size_t group, int quant)
{
	t_push_swap_list	*stack_tmp;

	if (!stack)
		return (0);
	if (stack->group == group)
		--quant;
	stack_tmp = stack->next;
	while (stack_tmp != stack && quant > 0)
	{
		if (stack_tmp->group == group)
			--quant;
		stack_tmp = stack_tmp->next;
	}
	if (quant <= 0)
		return (1);
	return (0);
}

static void	push_swap_group(t_push_swap_data *data, size_t group_src, size_t group_child, char spec)
{
	t_push_swap_list	*stack_tmp;
	t_push_swap_list	*stack;

	if (spec == 'a')
		stack = data->stack_a;
	else
		stack = data->stack_b;
	stack_tmp = stack;
	if ((stack_tmp->group == group_src || group_src == 0)
	&& ((spec == 'a' && stack_tmp->value <= data->avg)
	|| (spec == 'b' && stack_tmp->value >= data->avg)))
		stack_tmp->group = group_child;
	stack_tmp = stack_tmp->next;
	while (stack_tmp != stack)
	{
		if ((stack_tmp->group == group_src || group_src == 0)
		&& ((spec == 'a' && stack_tmp->value <= data->avg)
		|| (spec == 'b' && stack_tmp->value >= data->avg)))
			stack_tmp->group = group_child;
		stack_tmp = stack_tmp->next;
	}
}

void	p1(t_push_swap_data *data)
{
	size_t	i;

	while (!push_swap_max_group(data->stack_b, data->group, 1))
		data->group--;
	i = 0;
	if (data->stack_size == 100)//TODO add more specs for diff vars
		i = 2;
	while (i > 0)
	{
		if (push_swap_max_group(data->stack_b, data->group, 3))
		{
			data->avg = push_swap_avg(data->stack_b, data->group);// avg of group in b
			data->group++;// to mark next subgroup in b
			push_swap_group(data, data->group - 1, data->group, 'b');
		}
		--i;
	}
	push_swap_sort(data, 'b');//of last arrived group to b
}

static void	push_swap(t_push_swap_data *data)
{
	data->group = 0;
	data->stack_b = NULL;
	data->buff = NULL;
	data->stack_size = 100;
	while (!push_swap_sorted_a(data->stack_a) || data->stack_b != NULL)
	{
		while (push_swap_opt(data))
		{
			data->avg = push_swap_avg(data->stack_a, data->group);//of last arrived group to a or 0 on innit
			data->group++;// update counter to mark new group
			if (!push_swap_max_group(data->stack_a, data->group - 1, 1))//TODO rm cz has no effect
				push_swap_group(data, 0, data->group, 'a');
			else//TODO rm cz has no effect
				push_swap_group(data, data->group - 1, data->group, 'a');//TODO rm cz has no effect
			push_swap_sort(data, 'a');
		}
		if (data->stack_b != NULL)
			p1(data);
		if (push_swap_sorted_a(data->stack_a))
		{
			data->avg = INT_MAX;
			push_swap_group(data, 0, 0, 'a');
		}
	}
	push_swap_outp(&(data->buff));
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
//	system("leaks push_swap");
	return (1);
}
