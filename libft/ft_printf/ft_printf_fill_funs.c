/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fill_funs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_fill_flags(t_printf_funs *funs)
{
	funs['#'] = &ft_printf_hash;
	funs['+'] = &ft_printf_plus;
	funs[' '] = &ft_printf_blank;
}

static void	ft_printf_fill_length(t_printf_funs *funs)
{
	funs['l'] = &ft_printf_l;
	funs['h'] = &ft_printf_h;
	funs['L'] = &ft_printf_cap_l;
	funs['l' + 'l'] = &ft_printf_ll;
	funs['h' + 'h'] = &ft_printf_hh;
	funs[0] = &ft_printf_length0;
	funs['z'] = &ft_printf_z;
	funs['j'] = &ft_printf_j;
	funs['q'] = &ft_printf_ll;
	funs['t'] = &ft_printf_t;
}

static void	ft_printf_fill_convs(t_printf_convs *convs)
{
	convs['d'] = &ft_printf_di;
	convs['i'] = &ft_printf_di;
	convs['o'] = &ft_printf_o;
	convs['u'] = &ft_printf_u;
	convs['x'] = &ft_printf_x;
	convs['X'] = &ft_printf_cap_x;
	convs['c'] = &ft_printf_c;
	convs['s'] = &ft_printf_s;
	convs['p'] = &ft_printf_p;
	convs['f'] = &ft_printf_f;
	convs['F'] = &ft_printf_f;
	convs['%'] = &ft_printf_mod0;
	convs['U'] = &ft_printf_cap_u;
	convs['b'] = &ft_printf_b;
	convs['D'] = &ft_printf_cap_d;
	convs['O'] = &ft_printf_cap_o;
	convs['r'] = &ft_printf_r;
	convs['C'] = &ft_printf_cap_c;
	convs['S'] = &ft_printf_cap_s;
	convs[0] = &ft_printf_conv0;
}

void		ft_printf_fill_funs_convs(t_printf_funs **funs,
			t_printf_convs **convs)
{
	*funs = ft_memalloc(sizeof(t_printf_funs *) * 256);
	ft_printf_fill_flags(*funs);
	ft_printf_fill_length(*funs);
	*convs = ft_memalloc(sizeof(t_printf_convs *) * 128);
	ft_printf_fill_convs(*convs);
}
