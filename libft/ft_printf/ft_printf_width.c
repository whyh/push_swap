/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 20:38:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_width_minus(t_printf_mods mods, t_printf_buff *node,
			int length)
{
	char	*prefix;
	char	*tmp;

	prefix = ft_strnew((size_t)mods.width - length);
	prefix = ft_memset(prefix, ' ', (size_t)(mods.width - length));
	tmp = ft_strjoin(node->buff, prefix);
	ft_strdel(&(node->buff));
	ft_strdel(&prefix);
	node->buff = tmp;
}

static void	ft_printf_width_zero(t_printf_mods mods, t_printf_buff *node,
			int length)
{
	char	*prefix;

	prefix = ft_strnew((size_t)mods.width - length);
	prefix = ft_memset(prefix, '0', (size_t)(mods.width - length));
	--length;
	if (ft_strin(PRINTF_CHR, mods.conv) || ft_strin(PRINTF_STR, mods.conv)
	|| ft_strin(PRINTF_MOD0, mods.conv))
		length = -1;
	while (ft_strin(DEC, node->buff[length])
	|| (ft_strin(PRINTF_NDEC, mods.conv)
	&& ft_strin(ft_printf_base(mods.conv), node->buff[length])))
		--length;
	ft_strninject(&node->buff, prefix, (size_t)(length) + 1, -1);
	ft_strdel(&prefix);
}

static void	ft_printf_width_std(t_printf_mods mods, t_printf_buff *node,
			int length)
{
	char	*prefix;
	char	*tmp;

	prefix = ft_strnew((size_t)mods.width - length);
	prefix = ft_memset(prefix, ' ', (size_t)(mods.width - length));
	tmp = ft_strjoin(prefix, node->buff);
	ft_strdel(&(node->buff));
	ft_strdel(&prefix);
	node->buff = tmp;
}

void		ft_printf_width(t_printf_mods mods, t_printf_buff *node)
{
	int		length;

	length = (int)ft_strlen(node->buff);
	if (length >= mods.width)
		return ;
	if (mods.flags && ft_strin(mods.flags, '-'))
		ft_printf_width_minus(mods, node, length);
	else if (ft_printf_zero(mods))
		ft_printf_width_zero(mods, node, length);
	else
		ft_printf_width_std(mods, node, length);
}
