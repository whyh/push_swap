/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:47:29 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 19:26:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *str1, char const *str2, long n)
{
	size_t	len1;

	if (n == 0 || (str1 == NULL && str2 == NULL))
		return (1);
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (n < 0)
	{
		len1 = ft_strlen(str1);
		if (len1 != ft_strlen(str2))
			return (0);
		n = (int)len1;
	}
	--n;
	while (n >= 0 && str1[n] && str2[n])
	{
		if (str1[n] != str2[n])
			return (0);
		--n;
	}
	return (1);
}
