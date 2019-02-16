/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:35:38 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/16 22:56:02 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


int			ft_push_swap_sorted_a(t_push_swap_list *stack_a)
{
	t_push_swap_list	*tmp_stack_a;
	t_push_swap_list	*prev_stack_a;

	prev_stack_a = stack_a;
	tmp_stack_a = stack_a->next;
	while (tmp_stack_a != stack_a)
	{
		if (prev_stack_a->value > tmp_stack_a->value)
			return (0);
		prev_stack_a = prev_stack_a->next;
		tmp_stack_a = tmp_stack_a->next;
	}
	return (1);
}

int			ft_is_group(t_push_swap_list *stack_a, t_push_swap_list *stack_b,
			size_t group, char stack)
{
	t_push_swap_list	*tmp;

	if ((stack == 'a' && !stack_a) || (stack == 'b' && !stack_b))
		return (0);
	if (stack == 'a')
		tmp = stack_a;
	else
		tmp = stack_b;
	if (tmp->group == group)
		return (1);
	tmp = tmp->next;
	while (tmp != stack_a && tmp != stack_b)
	{
		if (tmp->group == group)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_push_swap_list	*ft_find_prev(t_push_swap_list **stack)
{
	t_push_swap_list	*tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	while (tmp->next != *stack)
		tmp = tmp->next;
	return (tmp);
}

void	ft_swap(t_push_swap_list **stack_a, t_push_swap_list **stack_b, char **buff)
{
	t_push_swap_list	*prev;

	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		prev = ft_find_prev(stack_a);
		ft_ss(stack_a, prev);
		ft_strninject(buff, " sa", -1, -1);
	}
	if (*stack_b && (*stack_b)->next
	&& (*stack_b)->value < (*stack_b)->next->value)
	{
		prev = ft_find_prev(stack_b);
		ft_ss(stack_b, prev);
		ft_strninject(buff, " sb", -1, -1);
	}
}

void	ft_rotate_rev(t_push_swap_list **stack_a, t_push_swap_list **stack_b, char **buff, char stack)
{
	t_push_swap_list	*prev;

	if (stack == 'a')
	{
		prev = ft_find_prev(stack_a);
		ft_rrr(stack_a, prev);
		ft_strninject(buff, " rra", -1, -1);
	}
	else if (stack == 'b')
	{
		prev = ft_find_prev(stack_b);
		ft_rrr(stack_b, prev);
		ft_strninject(buff, " rrb", -1, -1);
	}
}

void	ft_rotate(t_push_swap_list **stack_a, t_push_swap_list **stack_b, char **buff, char stack)
{
	if (stack == 'a')
	{
		ft_rr(stack_a);
		ft_strninject(buff, " ra", -1, -1);
	}
	else if (stack == 'b')
	{
		ft_rr(stack_b);
		ft_strninject(buff, " rb", -1, -1);
	}
}

void	ft_p(t_push_swap_list **stack_a, t_push_swap_list **stack_b, char **buff, char stack)
{
	t_push_swap_list	*prev_a;
	t_push_swap_list	*prev_b;

	prev_a = ft_find_prev(stack_a);
	prev_b = ft_find_prev(stack_b);
	if (stack == 'a')
	{
		ft_pp(stack_a, stack_b, prev_a, prev_b);
		ft_strninject(buff, " pb", -1, -1);
	}
	else if (stack == 'b')
	{
		ft_pp(stack_b, stack_a, prev_b, prev_a);
		ft_strninject(buff, " pa", -1, -1);
	}
}

int ft_dist(size_t group, t_push_swap_list **stack_a, t_push_swap_list **stack_b, char stack)
{
	t_push_swap_list	*tmp_stack;
	int					dist_pos;
	int					dist_neg;

	if (stack == 'a')
		tmp_stack = *stack_a;
	else
		tmp_stack = *stack_b;
	dist_pos = 0;
	while (tmp_stack->group != group)
	{
		tmp_stack = tmp_stack->next;
		++dist_pos;
	}
	if (stack == 'a')
		tmp_stack = *stack_a;
	else
		tmp_stack = *stack_b;
	dist_neg = 0;
	while (tmp_stack->group != group)
	{
		tmp_stack = ft_find_prev(&tmp_stack);
		--dist_neg;
	}
	return ((ft_abs(dist_pos) <= ft_abs(dist_neg)) ? dist_pos : dist_neg);
}

void		ft_push(t_push_swap_list **stack_a,
			t_push_swap_list **stack_b, char **buff, size_t group, char stack)
{
	int		dist;

	while (ft_is_group(*stack_a, *stack_b, group, stack))
	{
		ft_swap(stack_a, stack_b, buff);
		dist = ft_dist(group, stack_a, stack_b, stack);
		while (dist < 0)
		{
			++dist;
			ft_rotate_rev(stack_a, stack_b, buff, stack);
		}
		while (dist > 0)
		{
			--dist;
			ft_rotate(stack_a, stack_b, buff, stack);
		}
		if (stack == 'a' && ft_push_swap_sorted_a(*stack_a))
			break ;
		ft_p(stack_a, stack_b, buff, stack);
	}
	ft_swap(stack_a, stack_b, buff);
}

size_t		ft_push_swap_mark_a(t_push_swap_list *stack_a, size_t group, int avg)
{
	t_push_swap_list	*tmp_stack_a;
	size_t				n;

	tmp_stack_a = stack_a;
	n = 0;
	if (tmp_stack_a->value <= avg)
	{
		tmp_stack_a->group = group;
		++n;
	}
	else
		tmp_stack_a->group = 0;
	tmp_stack_a = tmp_stack_a->next;
	while (tmp_stack_a != stack_a)
	{
		if (tmp_stack_a->value <= avg)
		{
			tmp_stack_a->group = group;
			++n;
		}
		else
			tmp_stack_a->group = 0;
		tmp_stack_a = tmp_stack_a->next;
	}
	return (n);
}

int			ft_push_swap_avg(t_push_swap_list *stack)
{
	t_push_swap_list	*tmp_stack;
	int 				max;
	int 				min;
	int 				avg;
	int					error;

	max = stack->value;
	min = stack->value;
	tmp_stack = stack->next;
	while (tmp_stack != stack)
	{
		if (tmp_stack->value < min)
			min = tmp_stack->value;
		else if (tmp_stack->value > max)
			max = tmp_stack->value;
		tmp_stack = tmp_stack->next;
	}
	avg = (min + max) / 2;
	error = 0;
	while (avg + error != tmp_stack->value)
	{
		if (avg + error == tmp_stack->value)
			return (tmp_stack->value);
		tmp_stack = tmp_stack->next;
		while (tmp_stack != stack)
		{
			if (avg + error == tmp_stack->value)
				return (tmp_stack->value);
			tmp_stack = tmp_stack->next;
		}
		if (avg - error == tmp_stack->value)
			return (tmp_stack->value);
		tmp_stack = tmp_stack->next;
		while (tmp_stack != stack)
		{
			if (avg - error == tmp_stack->value)
				return (tmp_stack->value);
			tmp_stack = tmp_stack->next;
		}
		++error;
	}
	return (tmp_stack->value);
}

void	ft_optimise(char **buff)
{
	ft_strfrepl(buff, " sa sb", " ss", -1);
	ft_strfrepl(buff, " sb sa", " ss", -1);
	ft_strfrepl(buff, " ra rb", " rr", -1);
	ft_strfrepl(buff, " rb ra", " rr", -1);
	ft_strfrepl(buff, " rra rrb", " rrr", -1);
	ft_strfrepl(buff, " rrb rra", " rrr", -1);
}

static void	ft_push_swap(t_push_swap_list **stack_a)
{
	t_push_swap_list	*stack_b;
	size_t				group;
	char				*buff;
	int					avg;

	group = 0;
	stack_b = NULL;
	buff = NULL;
	while (!ft_push_swap_sorted_a(*stack_a) || stack_b != NULL)
	{
		while (!ft_push_swap_sorted_a(*stack_a))
		{
			++group;
			avg = ft_push_swap_avg(*stack_a);
			ft_push_swap_mark_a(*stack_a, group, avg);
			ft_push(stack_a, &stack_b, &buff, group, 'a');
		}
		if (stack_b != NULL)
		{
			ft_push(stack_a, &stack_b, &buff, group, 'b');
			--group;
		}
	}
	ft_optimise(&buff);
	ft_strfrepl(&buff, " ", "\n", -1);
	ft_printf("%s", buff);
}

static int	ft_push_swap_parse(size_t n, t_push_swap_list *stack_a, char **argv)
{
	size_t				i;
	size_t				i2;
	t_push_swap_list	*new_stack_a;

	i = 0;
	new_stack_a = stack_a;
	while (i < n)
	{
		if (i != 0)
		{
			new_stack_a->next = ft_memalloc(sizeof(stack_a) * n);
			new_stack_a = new_stack_a->next;
		}
		i2 = 0;
		while (argv[i + 1][i2])
		{
			if (!ft_strin(DEC, argv[i + 1][i2]))
				return (0);
			++i2;
		}
		new_stack_a->value = (int)ft_atoibase(DEC, argv[i + 1]);
		new_stack_a->pos = i;
		++i;
	}
	new_stack_a->next = stack_a;
	return (1);
}

int main(int argc, char **argv)
{
	t_push_swap_list	*stack_a;
	t_push_swap_list	*tmp_stack_a;
	size_t				n;

	if (argc == 2)
		return (1);
	if (argc < 2)
	{
		ft_printf("error: ...\n");
		ft_printf("usage: ...\n");
		return (0);
	}
	n = (size_t)(argc - 1);
	stack_a = ft_memalloc(sizeof(stack_a) * n);
	stack_a->next = NULL;
	if (!ft_push_swap_parse(n, stack_a, argv))
	{
		ft_printf("error: ...\n");
		ft_printf("usage: ...\n");
		return (0);
	}
	ft_push_swap(&stack_a);
	tmp_stack_a = ft_find_prev(&stack_a);
	tmp_stack_a->next = NULL;
	while (stack_a != NULL)
	{
		ft_printf("\n%d", stack_a->value);
		tmp_stack_a = stack_a->next;
		ft_memdel((void**)(&stack_a));
		stack_a = tmp_stack_a;
	}
	return (1);
}
