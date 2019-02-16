/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:14:29 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 19:26:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *memdst, const void *memsrc, long size)
{
	const char	*src;
	char		*dst;
	long		i;

	src = (CC*)memsrc;
	dst = (char*)memdst;
	if (src < dst)
	{
		--size;
		while (size >= 0)
		{
			dst[size] = src[size];
			--size;
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			dst[i] = src[i];
			++i;
		}
	}
	return (dst);
}
