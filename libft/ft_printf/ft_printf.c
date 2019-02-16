/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/08 12:28:17 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_exec(t_printf_mods *mods, va_list *args,
			t_printf_buff *node)
{
	static t_printf_funs	*funs = NULL;
	static t_printf_convs	*convs = NULL;
	int						i;

	if (!funs || !convs)
		ft_printf_fill_funs_convs(&funs, &convs);
	if (!convs[(int)mods->conv](args, mods, node, funs))
		return (0);
	if (!node->buff)
		return (1);
	if (mods->prec_spec == 1)
		ft_printf_prec(*mods, node);
	i = 0;
	while (mods->flags && mods->flags[i])
	{
		if (!ft_strin(PRINTF_PASIVE_FLAGS, mods->flags[i]))
			funs[(int)mods->flags[i]](args, *mods, node);
		++i;
	}
	if (mods->width != 0)
		ft_printf_width(*mods, node);
	return (1);
}

static int	ft_printf_parce_loop(char **format, va_list *args,
			t_printf_mods *mods)
{
	mods->width = 0;
	mods->prec_spec = 0;
	mods->prec = 0;
	mods->length = 0;
	mods->conv = '\0';
	mods->flags = NULL;
	mods->mod0 = '\0';
	while (ft_strin(PRINTF_FLAGS, **format) || ft_strin(DEC, **format)
	|| ft_strin(PRINTF_LENGTH1, **format) || ft_strin(PRINTF_LENGTH2, **format)
	|| ft_strin(PRINTF_PASIVE_FLAGS, **format)
	|| ft_strin(PRINTF_PARCE_CONST, **format))
	{
		ft_printf_parse_flags(format, mods);
		ft_printf_parse_f_width(format, mods, args);
		ft_printf_parce_prec(format, mods, args);
		ft_printf_parce_length(format, mods);
	}
	ft_printf_parce_conv(format, mods);
	if (mods->width == 0 && mods->prec_spec == 0 && mods->length == 0
	&& mods->conv == '\0')
		return (0);
	return (1);
}

static int	ft_printf_parse_mods(char **format, va_list *args,
			t_printf_buff *node)
{
	t_printf_mods	mods;
	t_printf_buff	*new_node;
	int				ret;

	if (format == NULL || *format == NULL || **format == '\0')
		return (0);
	if (!ft_printf_parce_loop(format, args, &mods))
		return (0);
	while (node->next != NULL)
		node = node->next;
	new_node = ft_memalloc(sizeof(t_printf_buff*) * 1);
	new_node->buff = NULL;
	new_node->next = NULL;
	node->next = new_node;
	ret = ft_printf_exec(&mods, args, new_node);
	ft_strdel(&(mods.flags));
	return (ret == 0 ? 0 : 1);
}

static int	ft_printf_iter(char **format, va_list *args, t_printf_buff *node)
{
	t_printf_buff	*new_node;
	size_t			size;

	while (**format)
	{
		if (ft_strin(PRINTF_MOD0, **format))
		{
			(*format)++;
			ft_printf_parse_mods(format, args, node);
		}
		if (**format && !ft_strin(PRINTF_MOD0, **format))
		{
			while (node->next != NULL)
				node = node->next;
			new_node = ft_memalloc(sizeof(t_printf_buff *) * 1);
			new_node->next = NULL;
			node->next = new_node;
			size = ft_strchr_i(*format, PRINTF_MOD0[0]);
			new_node->buff = ft_strndup(*format, size);
			if (ft_strin(new_node->buff, '[') || ft_strin(new_node->buff, '~'))
				ft_printf_collor(new_node, -1, NULL, NULL);
			(*format) += size;
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	size_t			chars_printed;
	t_printf_buff	*node;
	t_printf_buff	*prev_node;
	va_list			args;

	chars_printed = 0;
	node = ft_memalloc(sizeof(t_printf_buff*));
	node->next = NULL;
	node->buff = NULL;
	va_start(args, format);
	ft_printf_iter((char **)&format, &args, node);
	while (node != NULL)
	{
		if (node->buff != NULL)
			chars_printed += ft_printf_putstr(node->buff);
		ft_strdel(&(node->buff));
		prev_node = node;
		node = node->next;
		free(prev_node);
	}
	va_end(args);
	return ((int)chars_printed);
}
