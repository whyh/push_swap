/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cspf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/26 19:42:25 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	arg;

	if (funs[mods->length](args, *mods, node))
		return (1);
	arg = (char)va_arg(*args, int);
	if (arg == '\0')
	{
		node->buff = ft_strndup(PRINTF_MOD3, -1);
		return (1);
	}
	node->buff = ft_strnew(1);
	node->buff[0] = arg;
	return (1);
}

int		ft_printf_s(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	char	*arg;

	if (funs[mods->length](args, *mods, node))
		return (1);
	arg = va_arg(*args, char *);
	if (arg == NULL)
		node->buff = ft_strndup("(null)", -1);
	else
		node->buff = ft_strndup(arg, -1);
	return (1);
}

int		ft_printf_p(va_list *args, t_printf_mods *mods, t_printf_buff *node,
		t_printf_funs *funs)
{
	if (funs[mods->length](args, *mods, node))
		return (1);
	node->buff = ft_uitoabase(ft_printf_base(mods->conv),
	va_arg(*args, ULL));
	if (node->buff == NULL)
		ft_strninject(&(node->buff), "0", 0, -1);
	ft_strninject(&(node->buff), ft_printf_base_prefix(*mods, node), 0, -1);
	return (1);
}

void	ft_printf_fill_float(t_printf_buff *node, long long a_args[3],
		t_printf_mods mods)
{
	char	*tmp1;
	char	*tmp2;
	char	*base;

	base = ft_printf_base(mods.conv);
	tmp1 = ft_itoabase(base, a_args[0]);
	tmp2 = ft_strjoin(node->buff, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&(node->buff));
	tmp1 = ft_strjoin(tmp2, ".");
	ft_strdel(&tmp2);
	tmp2 = ft_itoabase(base, a_args[1]);
	node->buff = ft_strjoin(tmp1, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	tmp1 = ft_itoabase(base, a_args[2]);
	tmp2 = ft_strjoin(node->buff, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&(node->buff));
	node->buff = tmp2;
}

int		ft_printf_f(va_list *args, t_printf_mods *mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	double		arg;
	long long	a_args[3];

	if (mods->prec_spec == 0)
	{
		mods->prec = 6;
		mods->prec_spec = 1;
	}
	if (funs[mods->length](args, *mods, buff))
		return (1);
	arg = va_arg(*args, D);
	if (arg < 0 && (arg = -arg))
		buff->buff = ft_strndup("-", -1);
	a_args[0] = (LL)arg;
	arg -= a_args[0];
	arg = (arg * 1000000000000000000);
	a_args[1] = (LL)arg;
	arg -= a_args[1];
	arg = (arg * 1000000000000000000);
	a_args[2] = (LL)arg;
	ft_printf_fill_float(buff, a_args, *mods);
	return (1);
}
