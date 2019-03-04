/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:34:34 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 23:39:58 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	static_fill(t_push_swap_list *stack, int flag, int nbr)
{
	if (!flag)
	{
		stack->value = nbr;
		return (1);
	}
	while (stack->next != NULL)
	{
		if (stack->value == nbr)
		{
			ft_printf("[redError: multiple inclusions of one argument\n");
			return (0);
		}
		stack = stack->next;
	}
	if (stack->value == nbr)
	{
		ft_printf("[redError: multiple inclusions of one argument\n");
		return (0);
	}
	stack->next = ft_memalloc(sizeof(t_push_swap_list));
	stack->next->value = nbr;
	stack->next->next = NULL;
	return (1);
}

static int	static_invalid(char *arg, size_t i, long long nbr)
{

	if (nbr > INT_MAX || nbr < INT_MIN || (!ft_strin(DEC, arg[i])
	&& !(ft_strin(SIGNS, arg[i]) && ft_strin(DEC, arg[i + 1]))))
	{
		if (nbr > INT_MAX)
			ft_printf("[redError: at least one argument is too big\n");
		else if (nbr < INT_MIN)
			ft_printf("[redError: at least one argument is too small\n");
		else if (!ft_strin(DEC, arg[i])
		&& !(ft_strin(SIGNS, arg[i]) && ft_strin(DEC, arg[i + 1])))
			ft_printf("[redError: at least one argument isn't decimal\n");
		return (1);
	}
	return (0);
}

static int	static_parse_arg(t_push_swap_list **stack, char *arg, int flag)
{
	size_t		i;
	long long	nbr;

	i = 0;
	while (arg[i])
	{
		if (ft_strin(WHITESPACES, arg[i]) && (ft_strin(DEC, arg[i + 1])
		|| (ft_strin(SIGNS, arg[i + 1]) && ft_strin(DEC, arg[i + 2]))))
			++i;
		if (ft_strin(WHITESPACES, arg[i]) && !arg[i + 1] && i != 0)
			return (1);
		nbr = ft_atoibase(DEC, &(arg[i]));
		if (static_invalid(arg, i, nbr))
			return (0);
		if (!static_fill(*stack, flag, (int)nbr))
			return (0);
		flag = 1;
		++i;
		while (ft_strin(DEC, arg[i]))
			++i;
	}
	return (1);
}

int			push_swap_parse(t_push_swap_list **stack, size_t argc, char **argv,
			size_t i)
{
	t_push_swap_list	*tail;
	int					flag;

	*stack = NULL;
	if (i >= argc)
	{
		ft_printf("[redError: less then 2 arguments received\n");
		return (0);
	}
	*stack = ft_memalloc(sizeof(t_push_swap_list));
	(*stack)->next = NULL;
	flag = 0;
	while (i <= argc)
	{
		if (!static_parse_arg(stack, argv[i], flag))
			return (0);
		flag = 1;
		++i;
	}
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *stack;
	return (1);
}
