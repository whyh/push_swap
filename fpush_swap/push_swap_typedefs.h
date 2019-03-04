/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:25:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 19:27:03 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPEDEFS_H
# define PUSH_SWAP_TYPEDEFS_H

# define PUSH_SWAP_WIN_X 1500
# define PUSH_SWAP_WIN_Y 1000
# define PUSH_SWAP_WIDTH 250
# define PUSH_SWAP_SLOPE 150
# define PUSH_SWAP_STACK_A_X 300
# define PUSH_SWAP_STACK_B_X 950
# define PUSH_SWAP_STACK_Y 130
# define PUSH_SWAP_STACK_H 800
# define PUSH_SWAP_BORDER 6
# define PUSH_SWAP_RGB1 VIS_MUSTARD_YELLOW
# define PUSH_SWAP_RGB2 VIS_MAGMA_RED

typedef struct				s_push_swap_list
{
	int						value;
	int						g;
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
	int						group;
	char					*buff;
	size_t					stack_size;
}							t_push_swap_data;

typedef struct				s_push_swap_vis
{
	int 					t;
	int						v;
	void					*mlx;
	void					*win;
	void					*img;
	int						*img_data;
	int						min;
	int 					max;
	double					h;
	size_t					size;
	size_t 					init_size;
	double					slope;
	int 					pause;
	char 					*status;
	char					*buff;
	t_push_swap_list		**stack_b;
	t_push_swap_list		**stack_a;
	t_push_swap_list		**stack_buff;
	t_vis2d					data;
	int 					i;
	int 					mc;
	int 					ma;
	int 					mb;
	int 					mpc;
	int 					o;
	int 					count;
	int 					help;
}							t_push_swap_vis;

#endif
