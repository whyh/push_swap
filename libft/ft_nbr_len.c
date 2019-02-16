/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:11:21 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/12 11:11:21 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(long long nbr, size_t base)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		++len;
	}
	while (nbr / base > 0)
	{
		nbr = (LL)(nbr / base);
		++len;
	}
	return (len);
}

size_t	ft_unbrlen(unsigned long long nbr, size_t base)
{
	size_t	len;

	len = 1;
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		++len;
	}
	return (len);
}
