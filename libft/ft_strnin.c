/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:11:42 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/16 17:25:07 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_strnin(const char *str, const char *obj, long long field,
			long long n)
{
	long long	i;
	long long	i2;

	i = 0;
	if (field < 0)
		field = (long long)ft_strlen(str);
	if (n < 0)
		n = (long long)ft_strlen(obj);
	while (str[i] && i < field)
	{
		i2 = 0;
		while (str[i + i2] == obj[i2] && i2 < n && (i + i2) < field)
			++i2;
		if (i2 == n)
			return (i);
		++i;
	}
	return (-1);
}
