/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:16:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 16:47:08 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_t(t_push_swap_list *stack_a, t_push_swap_list *stack_b,
		char *status)
{
	size_t	size;

	ft_printf("status after [magenta[bold%s~]\n", status);
	ft_printf("[green stack A:~]");
	if (!(size = push_swap_stack_size(stack_a)))
		ft_printf("[cyan empty~]");
	while (size)
	{
		ft_printf(" [cyan%d~]", stack_a->value);
		stack_a = stack_a->next;
		--size;
	}
	ft_printf("\n[green stack B:~]");
	if (!(size = push_swap_stack_size(stack_b)))
		ft_printf("[cyan empty~]");
	while (size)
	{
		ft_printf(" [cyan%d~]", stack_b->value);
		stack_b = stack_b->next;
		--size;
	}
	ft_printf("\n");
}
