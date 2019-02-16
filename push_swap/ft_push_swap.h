/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:53:25 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/16 16:50:36 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct				s_push_swap_list
{
	int						value;
	size_t					pos;
	size_t					group;
	struct s_push_swap_list	*next;
}							t_push_swap_list;

typedef struct				s_push_swap_data
{

}							t_push_swap_data;


void	ft_ss(t_push_swap_list **stack, t_push_swap_list *prev);
void	ft_rr(t_push_swap_list **stack);
void	ft_rrr(t_push_swap_list **stack, t_push_swap_list *prev);
void	ft_pp(t_push_swap_list **stack_from, t_push_swap_list **stack_to,
		t_push_swap_list *prev_from, t_push_swap_list *prev_to);

#endif
