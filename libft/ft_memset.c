/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:45:41 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 19:26:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, unsigned char c, size_t len)
{
	char	*ptr;

	ptr = memptr;
	while (len > 0)
	{
		--len;
		ptr[len] = c;
	}
	return (ptr);
}
