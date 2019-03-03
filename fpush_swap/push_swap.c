/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:35:38 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 16:32:59 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_get_next(t_push_swap_data *data, char stack)
{
	int	next;

	if (stack == 'a')
		next = push_swap_next(*data, data->stack_a, &(data->stack_next), NULL);
	else
		next = push_swap_next(*data, data->stack_b, &(data->stack_next), NULL);
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

int	valid_next_next(t_push_swap_data *data)
{
	if (data->stack_next_next->g == data->group
	&& data->stack_next_next != data->stack_next)
		return (1);
	return (0);
}

static void	push_swap_sort(t_push_swap_data *data, char stack)
{
	if (stack == 'a')
		data->i = 0;
	while ((stack == 'a' && (!push_swap_sorted_a(data->stack_a)
	&& !push_swap_sorted(data->stack_a, data->group)))
	|| (stack == 'b' && !push_swap_sorted(data->stack_b, data->group)))
	{
		push_swap_swap(data, ' ');
		push_swap_get_next(data, stack);
		if (!(stack == 'a' && push_swap_sorted_a(data->stack_a)))
		{
			if (stack == 'b')
			{
				push_swap_next(*data, data->stack_b, &(data->stack_next_next), data->stack_next);
				while (data->stack_next->value > data->stack_a->value
				&& (data->stack_next->value > data->stack_a->next->value))
//				|| (valid_next_next(data) && data->stack_next_next->value > data->stack_a->value)))
				{
					push_swap_rotate(data, 'a');
					data->i++;
				}
			}
			push_swap_push(data, stack);
			if (stack == 'b' && data->stack_a->value > data->stack_a->next->value)
				push_swap_swap(data, 'a');
			while (data->i > 0)
			{
				push_swap_rotate_rev(data, 'a');
				data->i--;
			}
		}
	}
}

static void	push_swap_outp(char **buff)
{
	ft_strninject(buff, " ", 0, -1);
	ft_strfrepl(buff, " sa sb ", " ss ", -1);
	ft_strfrepl(buff, " sb sa ", " ss ", -1);
	ft_strfrepl(buff, " ra rb ", " rr ", -1);
	ft_strfrepl(buff, " rb ra ", " rr ", -1);
	ft_strfrepl(buff, " rra rrb ", " rrr ", -1);
	ft_strfrepl(buff, " rrb rra ", " rrr ", -1);
	ft_strneject(buff, " ", 1, -1);
	ft_strfrepl(buff, " ", "\n", -1);
	if (*buff == NULL)
		*buff = ft_strnew(0);
	ft_printf("%s", *buff);
	ft_strdel(buff);
}

int	push_swap_opt_next(t_push_swap_list *stack)
{
	t_push_swap_list	*stack_tmp1;
	t_push_swap_list	*stack_tmp2;
	int					r;
	int					rr;

	r = 0;
	stack_tmp1 = stack;
	while (stack_tmp1->value > push_swap_prev(stack_tmp1, 0)->value)
	{
		stack_tmp1 = stack_tmp1->next;
		++r;
	}
	rr = 0;
	stack_tmp2 = stack;
	while (stack_tmp2->value > push_swap_prev(stack_tmp2, 0)->value)
	{
		stack_tmp2 = push_swap_prev(stack_tmp2, 0);
		--rr;
	}
//	if (push_swap_sorted_a(stack_tmp1) && !push_swap_sorted_a(stack_tmp2))
//		return (r);
//	if (!push_swap_sorted_a(stack_tmp1) && push_swap_sorted_a(stack_tmp2))
//		return (rr);
//	if (push_swap_sorted_a(stack_tmp1) && push_swap_sorted_a(stack_tmp2))
	return ((ft_abs(r) < ft_abs(rr)) ? r : rr);
//	return (0);
}

size_t	push_swap_count_group(t_push_swap_list *stack, int group)
{
	size_t	stack_size;
	size_t	n;

	stack_size = push_swap_stack_size(stack);
	n = 0;
	while (stack_size > 0)
	{
		if (stack->g == group)
			++n;
		stack = stack->next;
		--stack_size;
	}
	return (n);
}

static void	push_swap_group(t_push_swap_data *data, int group_targ,
			int group_new, char spec)
{
	t_push_swap_list	*stack;
	size_t				stack_size;

	if (spec == 'a')
		stack = data->stack_a;
	else
		stack = data->stack_b;
	stack_size = push_swap_stack_size(stack);
	while (stack_size)
	{
		if ((stack->g == group_targ || group_targ == 0)
			&& ((spec == 'b' && stack->value >= data->avg)
				|| (spec == 'a' && stack->value <= data->avg)))
			stack->g = group_new;
		stack = stack->next;
		--stack_size;
	}
}

int			push_swap_opt(t_push_swap_data *data)
{
	int	n;

	if (push_swap_sorted_a(data->stack_a))
	{
		data->avg = INT_MAX;
		push_swap_group(data, 0, 0, 'a');
		return (0);
	}
	if (data->stack_a->value > data->stack_a->next->value
	&& (data->stack_a->value < data->stack_a->next->next->value
	|| (push_swap_stack_size(data->stack_a) == 3
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

void	get_specs(t_push_swap_data data, size_t *loop, size_t *min)
{
	if (data.stack_size <= 250)
	{
		*loop = 2;//2
		*min = 5;//5
	}//100
	else
	{
		*loop = 3;//3
		*min = 25;//25
	}//500
}

void	push_swap_pull(t_push_swap_data *data)
{
	size_t	loop;
	size_t	min;

	while (!push_swap_count_group(data->stack_b, data->group))
		data->group--;
	get_specs(*data, &loop, &min);
	while (loop > 0)
	{
		if (min <= push_swap_count_group(data->stack_b, data->group))
		{
			data->avg = push_swap_avg(data->stack_b, data->group);
			data->group++;
			push_swap_group(data, data->group - 1, data->group, 'b');
		}
		--loop;
	}
	push_swap_sort(data, 'b');
}

static void	push_swap(t_push_swap_data *data)
{
	data->group = 0;
	data->stack_b = NULL;
	data->buff = NULL;
	data->stack_size = push_swap_stack_size(data->stack_a);
	while (!push_swap_sorted_a(data->stack_a) || data->stack_b != NULL)
	{
		while (push_swap_opt(data))
		{
			data->avg = push_swap_avg(data->stack_a, data->group);
			data->group++;
			if (!push_swap_count_group(data->stack_a, data->group - 1))//TODO rm cz has no effect
				push_swap_group(data, 0, data->group, 'a');
			else//TODO rm cz has no effect
				push_swap_group(data, data->group - 1, data->group, 'a');//TODO rm cz has no effect
			push_swap_sort(data, 'a');
		}
		if (data->stack_b != NULL)
			push_swap_pull(data);
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
	if (!push_swap_parse(&(data.stack_a), (size_t)(argc - 1), argv, 1))
	{
		push_swap_free_stack(&(data.stack_a));
		ft_printf("error: invalid argument\n");
		ft_printf("usage: ./push_swap \"1 3 2 4 5 7 6 8 0 9\"\n");
		return (0);
	}
	push_swap(&data);
	push_swap_free_stack(&(data.stack_a));
	return (1);
}
