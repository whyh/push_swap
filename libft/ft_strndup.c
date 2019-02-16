/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:25:16 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 18:05:37 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, long n)
{
	char	*dst;

	if (n < 0)
		n = ft_strlen(src);
	if (!(dst = ft_strnew((size_t)n)))
		return (NULL);
	dst = ft_strncpy(dst, src, n);
	return (dst);
}
