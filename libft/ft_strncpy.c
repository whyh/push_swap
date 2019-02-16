/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:14:59 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 19:55:25 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, long n)
{
	long	i;

	i = 0;
	if (n < 0)
		n = ft_strlen(src);
	while (i < n && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i <= n)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}
