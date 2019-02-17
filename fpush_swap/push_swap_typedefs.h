/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:25:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/17 21:47:20 by dderevyn         ###   ########.fr       */
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

typedef struct				s_push_swap_sort
{
	size_t					group;
	char					*buff;
}							t_push_swap_sort;

#endif
