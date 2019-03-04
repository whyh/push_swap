/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:35:38 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 21:44:24 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	static_sort_b(t_push_swap_data *data)
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

static void	static_sort(t_push_swap_data *data)
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
			static_sort_b(data);
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
	static_sort(&data);
	push_swap_free_stack(&(data.stack_a));
	return (1);
}
