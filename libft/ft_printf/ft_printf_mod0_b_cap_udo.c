/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod0_b_cap_udo.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_mod0(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_strndup(&(mods->mod0), 1);
	return (1);
}

int		ft_printf_cap_u(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	(void)funs;
	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	node->buff = ft_uitoabase(base, va_arg(*args, ULL));
	return (1);
}

int		ft_printf_cap_d(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	(void)funs;
	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	node->buff = ft_itoabase(base, va_arg(*args, L));
	return (1);
}

int		ft_printf_cap_o(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	(void)funs;
	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	node->buff = ft_uitoabase(base, va_arg(*args, UL));
	return (1);
}

int		ft_printf_b(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*base;

	if (mods->prec_spec == 0)
		mods->prec = 1;
	base = ft_printf_base(mods->conv);
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_uitoabase(base, va_arg(*args, UI));
	return (1);
}
