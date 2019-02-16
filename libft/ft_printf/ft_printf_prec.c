/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_prec_sn_usn_p_ndec(t_printf_mods mods,
		t_printf_buff *node)
{
	int		length;
	char	*head;
	int		i;

	if (mods.prec == 0)
	{
		i = 0;
		if (ft_strin(PRINTF_PTR, mods.conv))
			i = 2;
		if (node->buff[i] == '0' && node->buff[i + 1] == '\0')
			node->buff[i] = '\0';
		return ;
	}
	length = mods.prec - (int)ft_strlen(node->buff);
	i = 0;
	if (ft_strin(PRINTF_PTR, mods.conv) && (i = 2))
		length += 2;
	if (node->buff[0] == '-' && (i = 1))
		++length;
	if (length <= 0)
		return ;
	head = ft_strnew((size_t)length);
	head = ft_memset(head, '0', (size_t)length);
	ft_strninject(&(node->buff), head, (size_t)i, -1);
	ft_strdel(&head);
}

static void	ft_printf_prec_str(t_printf_mods mods, t_printf_buff *node)
{
	char	*tmp;

	if (mods.prec >= (int)ft_strlen(node->buff))
		return ;
	tmp = ft_strnew((size_t)mods.prec);
	tmp = ft_strncpy(tmp, node->buff, (size_t)mods.prec);
	ft_strdel(&(node->buff));
	node->buff = tmp;
}

static void	ft_printf_prec_float_fix(t_printf_buff *node, t_printf_mods mods,
			int length, int size)
{
	int i;
	int mod;

	mod = 0;
	while (length > mods.prec - 1)
	{
		if (node->buff[size] > '5')
		{
			i = 1;
			while (node->buff[size - i] == '9' || node->buff[size - i] == '.')
				if (node->buff[size - i++] == '9')
					node->buff[size - i + 1] = '0';
			if (size - i >= 0 && node->buff[size - i] != '-')
				node->buff[size - i]++;
			else if (node->buff[size - i] == '-' && (mod += 1))
				ft_strninject(&(node->buff), "1", 1, -1);
			else if ((mod += 1))
				ft_strninject(&(node->buff), "1", 0, -1);
		}
		node->buff[size] = '\0';
		--size;
		--length;
	}
	if (mods.prec == 0)
		node->buff[size + mod] = '\0';
}

static void	ft_printf_prec_float(t_printf_mods mods, t_printf_buff *node)
{
	char	*tmp;
	char	*tmp2;
	int		length;
	int		size;

	tmp = ft_strchr(node->buff, '.');
	if (tmp != NULL)
		length = (int)ft_strlen(tmp + 1) - 1;
	else
		length = 0;
	if (length < mods.prec)
	{
		tmp = ft_strnew((size_t)(mods.prec - length - 1));
		ft_memset(tmp, '0', (size_t)(mods.prec - length - 1));
		tmp2 = ft_strjoin(node->buff, tmp);
		ft_strdel(&(node->buff));
		ft_strdel(&tmp);
		node->buff = tmp2;
		return ;
	}
	size = (int)ft_strlen(node->buff) - 1;
	ft_printf_prec_float_fix(node, mods, length, size);
}

void		ft_printf_prec(t_printf_mods mods, t_printf_buff *node)
{
	if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_PTR, mods.conv)
	|| ft_strin(PRINTF_USN, mods.conv) || ft_strin(PRINTF_NDEC, mods.conv))
		ft_printf_prec_sn_usn_p_ndec(mods, node);
	else if (ft_strin(PRINTF_FLOAT, mods.conv))
		ft_printf_prec_float(mods, node);
	else if (ft_strin(PRINTF_STR, mods.conv))
		ft_printf_prec_str(mods, node);
}
