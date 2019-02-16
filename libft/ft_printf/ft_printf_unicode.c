/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/08 13:05:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_printf_bit_size(wchar_t arg)
{
	unsigned int	ui;
	size_t			i;

	ui = (UI)arg;
	i = 0;
	while (ui > 0)
	{
		++i;
		ui = ui >> 1;
	}
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else if (i <= 21)
		return (4);
	else
		return (0);
}

static void		ft_printf_wchar(unsigned int ui, const unsigned int *mask,
				size_t size, char **tmp)
{
	if (size == 1)
		(*tmp)[0] = (char)ui;
	else if (size == 2)
	{
		(*tmp)[0] = (char)((mask[0] >> 8) | (((ui >> 6) << 27) >> 27));
		(*tmp)[1] = (char)(((mask[0] << 24) >> 24) | ((ui << 26) >> 26));
	}
	else if (size == 3)
	{
		(*tmp)[0] = (char)((mask[1] >> 16) | (((ui >> 12) << 28) >> 28));
		(*tmp)[1] = (char)(((mask[1] << 16) >> 24) | (((ui >> 6) << 26) >> 26));
		(*tmp)[2] = (char)(((mask[1] << 24) >> 24) | ((ui << 26) >> 26));
	}
	else if (size == 4)
	{
		(*tmp)[0] = (char)
		((((mask[2] >> 24) << 24) | (((ui >> 18) << 29) >> 29)));
		(*tmp)[1] = (char)
		((((mask[2] >> 16) << 24) >> 24) | (((ui >> 12) << 26) >> 26));
		(*tmp)[2] = (char)
		((((mask[2] >> 8) << 24) >> 24) | (((ui >> 6) << 26) >> 26));
		(*tmp)[3] = (char)(((mask[2] << 24) >> 24) | ((ui << 26) >> 26));
	}
	(*tmp)[size] = '\0';
}

static void		ft_printf_compose_mask(unsigned **mask)
{
	if (mask && *mask == NULL)
	{
		*mask = ft_memalloc(sizeof(unsigned) * 3);
		(*mask)[0] = 49280;
		(*mask)[1] = 14712960;
		(*mask)[2] = 4034953344;
	}
	else if (mask)
		ft_memdel((void**)mask);
}

int				ft_printf_cap_c(va_list *args, t_printf_mods *mods,
				t_printf_buff *node, t_printf_funs *funs)
{
	wchar_t		arg;
	size_t		size;
	unsigned	*mask;

	(void)funs;
	(void)mods;
	arg = va_arg(*args, wchar_t);
	if (arg == '\0')
	{
		node->buff = ft_strndup(PRINTF_MOD3, -1);
		return (1);
	}
	size = ft_printf_bit_size(arg);
	node->buff = ft_strnew(size);
	mask = NULL;
	ft_printf_compose_mask(&mask);
	ft_printf_wchar((UI)arg, mask, size, &(node->buff));
	ft_printf_compose_mask(&mask);
	return (1);
}

int				ft_printf_cap_s(va_list *args, t_printf_mods *mods,
				t_printf_buff *node, t_printf_funs *funs)
{
	wchar_t		*arg;
	char		*tmp;
	size_t		size;
	unsigned	*mask;
	size_t		i[2];

	(void)funs;
	(void)mods;
	if (!(arg = va_arg(*args, wchar_t*)))
		node->buff = ft_strndup("(null)", -1);
	i[0] = 0;
	i[1] = 0;
	mask = NULL;
	ft_printf_compose_mask(&mask);
	while (arg != NULL && arg[i[0]])
	{
		size = ft_printf_bit_size(arg[i[0]]);
		tmp = ft_strnew(size);
		ft_printf_wchar((UI)arg[i[0]], mask, size, &tmp);
		ft_strninject(&(node->buff), tmp, (i[0])++ + i[1], -1);
		ft_strdel(&tmp);
		i[1] += size - 1;
	}
	ft_printf_compose_mask(&mask);
	return (1);
}
