/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_zjt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_z(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (ft_strin(PRINTF_USN, mods.conv) || ft_strin(PRINTF_NDEC, mods.conv))
		node->buff = ft_uitoabase(base, va_arg(*args, size_t));
	else if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
		node->buff = ft_itoabase(base, va_arg(*args, ssize_t));
	else
		return (0);
	return (1);
}

int	ft_printf_j(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (ft_strin(PRINTF_USN, mods.conv) || ft_strin(PRINTF_NDEC, mods.conv))
		node->buff = ft_uitoabase(base, va_arg(*args, uintmax_t));
	else if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
		node->buff = ft_itoabase(base, va_arg(*args, intmax_t));
	else
		return (0);
	return (1);
}

int	ft_printf_t(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (ft_strin(PRINTF_NDEC, mods.conv) || ft_strin(PRINTF_USN, mods.conv))
		node->buff = ft_uitoabase(base, va_arg(*args, uintptr_t));
	else if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv))
		node->buff = ft_itoabase(base, va_arg(*args, ptrdiff_t));
	else
		return (0);
	return (1);
}
