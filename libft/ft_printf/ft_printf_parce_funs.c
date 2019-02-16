/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parce_funs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_get_asterix(t_printf_mods *mods, va_list *args,
		char *mod, char **format)
{
	int		i;

	(*format)++;
	i = va_arg(*args, int);
	if (ft_strncmp(mod, "width", -1))
	{
		if (i < 0)
		{
			i *= -1;
			if (!mods->flags || !ft_strin(mods->flags, '-'))
				ft_strninject(&(mods->flags), "-", 0, -1);
		}
		mods->width = i;
	}
	else if (ft_strncmp(mod, "prec", -1))
	{
		if (i >= 0)
			mods->prec = i;
		else
			mods->prec_spec = 0;
	}
}

int		ft_printf_compare_length(int length, int modslength, int i2, int i)
{
	size_t	size;
	char	*size_table;

	size = ft_strlen(PRINTF_LENGTH1) - 1;
	size_table = ft_strnew(size);
	while (++i2 < (int)size - 1)
		size_table[i2] = PRINTF_LENGTH1[i2];
	i2 = 0;
	while (size_table[i] && size_table[i] != modslength)
		++i;
	if (modslength == PRINTF_LENGTH2[0] + PRINTF_LENGTH2[0])
		i = 0;
	else if (modslength == PRINTF_LENGTH2[1] + PRINTF_LENGTH2[1])
		i = (int)size - 1;
	while (size_table[i2] && size_table[i2] != length)
		++i2;
	if (length == PRINTF_LENGTH2[0] + PRINTF_LENGTH2[0])
		i2 = 0;
	else if (length == PRINTF_LENGTH2[1] + PRINTF_LENGTH2[1])
		i2 = (int)size - 1;
	if (i2 > i)
		return (1);
	ft_strdel(&size_table);
	return (0);
}
