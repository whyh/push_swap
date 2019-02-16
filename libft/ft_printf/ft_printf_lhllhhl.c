/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lhllhhl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_l(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (ft_strin(PRINTF_NDEC, mods.conv) || ft_strin(PRINTF_USN, mods.conv))
		node->buff = ft_uitoabase(base, va_arg(*args, UL));
	else if (ft_strin(PRINTF_FLOAT, mods.conv)
	|| ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
		node->buff = ft_itoabase(base, va_arg(*args, L));
	else
		return (0);
	return (1);
}

int	ft_printf_h(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (ft_strin(PRINTF_USN, mods.conv) || ft_strin(PRINTF_NDEC, mods.conv))
		node->buff = ft_uitoabase(base, (US)va_arg(*args, int));
	else if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
		node->buff = ft_itoabase(base, (S)va_arg(*args, int));
	else
		return (0);
	return (1);
}

int	ft_printf_ll(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (ft_strin(PRINTF_NDEC, mods.conv) || ft_strin(PRINTF_USN, mods.conv))
		node->buff = ft_uitoabase(base, va_arg(*args, ULL));
	else if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
		node->buff = ft_itoabase(base, va_arg(*args, LL));
	else
		return (0);
	return (1);
}

int	ft_printf_hh(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (ft_strin(PRINTF_NDEC, mods.conv) || ft_strin(PRINTF_USN, mods.conv))
		node->buff = ft_uitoabase(base, (UC)va_arg(*args, int));
	else if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
		node->buff = ft_itoabase(base, (char)va_arg(*args, int));
	else
		return (0);
	return (1);
}

int	ft_printf_cap_l(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	long double	arg;
	long long	a_args[3];

	if (ft_strin(PRINTF_FLOAT, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
	{
		arg = va_arg(*args, LD);
		if (arg < 0 && (arg = -arg))
			node->buff = ft_strndup("-", -1);
		a_args[0] = (LL)arg;
		arg -= a_args[0];
		arg = (arg * 1000000000000000000);
		a_args[1] = (LL)arg;
		arg -= a_args[1];
		arg = (arg * 1000000000000000000);
		a_args[2] = (LL)arg;
		ft_printf_fill_float(node, a_args, mods);
	}
	else
		return (0);
	return (1);
}
