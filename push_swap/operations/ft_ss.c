/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:39:15 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/16 20:08:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_ss(t_push_swap_list **stack, t_push_swap_list *prev)
{
	t_push_swap_list	*tmp;

	tmp = (*stack)->next;
	prev->next = tmp;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}
