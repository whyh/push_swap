/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:39:10 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/16 21:52:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_pp(t_push_swap_list **stack_from, t_push_swap_list **stack_to,
		t_push_swap_list *prev_from, t_push_swap_list *prev_to)
{
	t_push_swap_list	*tmp;

	tmp = *stack_from;
	*stack_from = tmp->next;
	prev_from->next = tmp->next;
	if (prev_to)
		prev_to->next = tmp;
	if (*stack_to)
		tmp->next = *stack_to;
	else
		tmp->next = tmp;
	*stack_to = tmp;
	if (*stack_from == prev_from && *stack_to == *stack_from)
		*stack_from = NULL;
}
