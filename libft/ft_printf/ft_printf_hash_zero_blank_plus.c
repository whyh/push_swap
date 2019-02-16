/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hash_zero_blank_plus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_plus(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	size_t	i;
	char	*tmp;

	(void)args;
	if (!ft_strin(PRINTF_SN, mods.conv) && !ft_strin(PRINTF_FLOAT, mods.conv))
		return (1);
	i = 0;
	while (node->buff[i] != '\0' && node->buff[i] != '-'
	&& !ft_strin(DEC, node->buff[i]))
		++i;
	if (node->buff[i] == '-')
		return (1);
	tmp = ft_strjoin("+", node->buff);
	ft_strdel(&(node->buff));
	node->buff = tmp;
	return (1);
}

int	ft_printf_blank(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	size_t	i;
	char	*tmp;

	(void)args;
	if (!ft_strin(PRINTF_SN, mods.conv) || ft_strin(mods.flags, '+'))
		return (1);
	i = 0;
	while (node->buff[i] != '\0' && node->buff[i] != '-'
	&& ft_strin(DEC, node->buff[i]))
		++i;
	if (node->buff[i] == '-')
		return (1);
	tmp = ft_strjoin(" ", node->buff);
	ft_strdel(&(node->buff));
	node->buff = tmp;
	return (1);
}

int	ft_printf_hash(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	int i;

	(void)args;
	if (ft_strin(PRINTF_NDEC, mods.conv))
	{
		i = 0;
		while (node->buff[i]
		&& !ft_strin(ft_printf_base(mods.conv), node->buff[i]))
			++i;
		ft_strninject(&(node->buff), ft_printf_base_prefix(mods, node), i, -1);
	}
	else if (ft_strin(PRINTF_FLOAT, mods.conv) && !ft_strin(node->buff, '.'))
		ft_strninject(&(node->buff), ".", -1, -1);
	return (1);
}

int	ft_printf_zero(t_printf_mods mods)
{
	if (!mods.flags || !ft_strin(mods.flags, '0'))
		return (0);
	if (mods.prec_spec == 0 && (ft_strin(PRINTF_NDEC, mods.conv)
	|| ft_strin(PRINTF_USN, mods.conv) || ft_strin(PRINTF_SN, mods.conv)))
		return (1);
	else if (ft_strin(PRINTF_CHR, mods.conv) || ft_strin(PRINTF_STR, mods.conv)
	|| ft_strin(PRINTF_MOD0, mods.conv) || ft_strin(PRINTF_PTR, mods.conv)
	|| ft_strin(PRINTF_FLOAT, mods.conv))
		return (1);
	return (0);
}
