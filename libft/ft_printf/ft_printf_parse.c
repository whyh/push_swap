/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 20:37:21 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_parse_flags(char **format, t_printf_mods *mods)
{
	int		i;
	char	*tmp;

	if (**format == '\0')
		return ;
	i = 0;
	while (ft_strin(PRINTF_FLAGS, **format)
	|| ft_strin(PRINTF_PASIVE_FLAGS, **format))
	{
		if (!mods->flags || !ft_strin(mods->flags, **format))
		{
			tmp = ft_strndup(*format, 1);
			ft_strninject(&(mods->flags), tmp, 0, -1);
			ft_strdel(&tmp);
			++i;
		}
		while (**format == *(*format + 1))
			(*format)++;
		(*format)++;
	}
}

void	ft_printf_parse_f_width(char **format, t_printf_mods *mods,
		va_list *args)
{
	int	width;

	if (**format == '\0' || **format == '0')
		return ;
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "width", format);
	if (ft_strin(DEC, **format))
	{
		width = 0;
		while (ft_strin(DEC, **format))
		{
			width = width * 10 + **format - '0';
			(*format)++;
		}
		mods->width = width;
	}
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "width", format);
}

void	ft_printf_parce_prec(char **format, t_printf_mods *mods, va_list *args)
{
	int	prec;

	if (**format != '.')
		return ;
	mods->prec_spec = 1;
	mods->prec = 0;
	(*format)++;
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "prec", format);
	if (ft_strin(DEC, **format))
	{
		prec = 0;
		while (ft_strin(DEC, **format))
		{
			prec = prec * 10 + **format - '0';
			(*format)++;
		}
		mods->prec = prec;
	}
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "prec", format);
}

void	ft_printf_parce_length(char **format, t_printf_mods *mods)
{
	int		length;

	if (!ft_strin(PRINTF_LENGTH1, **format))
		return ;
	length = **format;
	(*format)++;
	if (ft_strin(PRINTF_LENGTH2, **format) && **format == *(*format - 1))
	{
		length += **format;
		(*format)++;
	}
	if (mods->length == 0
	|| ft_printf_compare_length(length, mods->length, -1, 0))
		mods->length = length;
}

int		ft_printf_parce_conv(char **format, t_printf_mods *mods)
{
	if (!ft_strin(PRINTF_SN, **format) && !ft_strin(PRINTF_USN, **format)
	&& !ft_strin(PRINTF_CHR, **format) && !ft_strin(PRINTF_NDEC, **format)
	&& !ft_strin(PRINTF_FLOAT, **format) && !ft_strin(PRINTF_PTR, **format)
	&& !ft_strin(PRINTF_STR, **format))
	{
		mods->conv = PRINTF_MOD0[0];
		mods->mod0 = **format;
	}
	else
		mods->conv = **format;
	if (**format != '\0')
		(*format)++;
	if (mods->length == 'l' && ft_strin(PRINTF_CAPL, mods->conv))
	{
		mods->conv -= ASCII_SHIFT;
		mods->length = '\0';
	}
	return (1);
}
