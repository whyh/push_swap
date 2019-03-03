/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:53:25 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 21:27:34 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "push_swap_typedefs.h"

void				push_swap_rr(t_push_swap_list **stack);
void				push_swap_rrr(t_push_swap_list **stack);
void				push_swap_ss(t_push_swap_list **stack);
void				push_swap_pp(t_push_swap_list **stack_from,
					t_push_swap_list **stack_to);
void				push_swap_free_stack(t_push_swap_list **stack);
t_push_swap_list	*push_swap_prev(t_push_swap_list *stack, int group);
int					push_swap_sorted_a(t_push_swap_list *stack);
int					push_swap_sorted(t_push_swap_list *stack, int group);
int					push_swap_next(t_push_swap_data data,
					t_push_swap_list *stack, t_push_swap_list **stack_next,
					t_push_swap_list *stack_avoid);
void				push_swap_swap(t_push_swap_data *data, char stack);
void				push_swap_rotate_rev(t_push_swap_data *data, char stack);
void				push_swap_rotate(t_push_swap_data *data, char stack);
void				push_swap_push(t_push_swap_data *data, char stack);
int					push_swap_avg(t_push_swap_list *stack, int group);
int					push_swap_parse(t_push_swap_list **stack, size_t argc, char **argv,
					size_t i);
size_t				push_swap_stack_size(t_push_swap_list *stack);
void 				push_swap_parse_vt(char *arg, t_push_swap_vis *vis, size_t *i);
int					push_swap_valid(char *line);
void				push_swap_exit(t_push_swap_vis *vis);
void				push_swap_exec(t_push_swap_vis *vis, char *buff);


void				push_swap_t(t_push_swap_list *stack_a,
					t_push_swap_list *stack_b, char *status);
void				push_swap_v_draw_pauseb(t_push_swap_vis *vis);

void				push_swap_v(t_push_swap_vis *vis);
void				push_swap_v_init(t_push_swap_vis *vis);
double				push_swap_v_slope(int value, int min, int max);
int 				push_swap_v_key_release(int keycode, void *param);
int 				push_swap_v_key_press(int keycode, void *param);
int 				push_swap_v_close(void *param);
int 				push_swap_v_loop(void *param);
void				push_swap_v_draw(t_push_swap_vis *vis);
void				push_swap_v_start(t_push_swap_vis *vis);
void				push_swap_v_draw_playb(t_push_swap_vis *vis);
void				push_swap_v_draw_bg(t_push_swap_vis *vis);
void				push_swap_v_draw_stack(t_push_swap_vis *vis, char spec);
int 				push_swap_v_mouse_move(int x, int y, void *param);
int				 	push_swap_v_mouse_press(int button, int x, int y, void *param);
int 				push_swap_v_mouse_release(int button, int x, int y, void *param);

#endif
