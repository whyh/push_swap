/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:25:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/23 15:54:24 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPEDEFS_H
# define PUSH_SWAP_TYPEDEFS_H

typedef struct				s_push_swap_list
{
	int						value;
	size_t					group;
	struct s_push_swap_list	*next;
}							t_push_swap_list;

typedef struct				s_push_swap_data
{
	t_push_swap_list		*stack_a;
	t_push_swap_list		*stack_b;
	t_push_swap_list		*stack_next;
	t_push_swap_list		*stack_next_next;
	int						avg;
	size_t					i;
	size_t					group;
	char					*buff;
	size_t					stack_size;
}							t_push_swap_data;

typedef struct				s_push_swap_options
{
	int						v;
	int 					t;
}							t_push_swap_options;

#endif
