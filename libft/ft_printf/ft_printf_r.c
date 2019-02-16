/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 21:31:23 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_unprint(t_printf_buff *node, char *arg)
{
	char	unprint[128];
	int		i;
	int		i2;

	unprint[127] = '?';
	i = 0;
	while (++i <= '_')
		unprint[i] = (char)(i + 64);
	i = -1;
	i2 = 0;
	while (arg[++i])
	{
		if ((arg[i] > 0 && arg[i] < ' ') || (arg[i] == 127))
		{
			node->buff[i2] = '^';
			++i2;
			node->buff[i2] = unprint[(int)(arg[i])];
		}
		else
			node->buff[i2] = arg[i];
		++i2;
	}
}

int			ft_printf_r(va_list *args, t_printf_mods *mods, t_printf_buff *node,
			t_printf_funs *funs)
{
	char	*arg;
	int		i;
	int		i2;

	if (funs[mods->length](args, *mods, node))
		return (1);
	arg = va_arg(*args, char *);
	if (arg == NULL)
	{
		node->buff = ft_strndup("(null)", -1);
		return (0);
	}
	i = 0;
	i2 = 0;
	while (arg[i])
	{
		if ((arg[i] > 0 && arg[i] < ' ') || (arg[i] == 127))
			++i2;
		++i;
	}
	node->buff = ft_strnew((size_t)i + i2);
	ft_printf_unprint(node, arg);
	return (1);
}
