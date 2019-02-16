/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:37:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 19:26:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t n)
{
	const char	*str1;
	const char	*str2;

	str1 = mem1;
	str2 = mem2;
	if (n == 0 || (str1 == NULL && str2 == NULL))
		return (1);
	if (str1 == NULL || str2 == NULL)
		return (0);
	--n;
	while (n > 0 && str1[n] && str2[n])
	{
		if (str1[n] != str2[n])
			return (0);
		--n;
	}
	if (str1[n] != str2[n])
		return (0);
	return (1);
}
