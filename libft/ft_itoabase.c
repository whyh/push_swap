/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:33:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 19:07:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	static_ft_fdset(char *set)
{
	int	i;
	int	i2;

	i = 0;
	while (set[i])
	{
		if (!ft_strin(ALPHABET, set[i]) && !ft_strin(ALPHABET_CAP, set[i])
		&& !ft_strin(DEC, set[i]))
			return (1);
		++i;
	}
	i = 0;
	while (set[i])
	{
		i2 = i + 1;
		while (set[i2])
			if (set[i] == set[i2++])
				return (1);
		++i;
	}
	if (i < 2)
		return (1);
	return (0);
}

char		*ft_itoabase(char *set, long long nbr)
{
	char	*str;
	size_t	base;
	size_t	len;

	if (!set || static_ft_fdset(set))
		return (NULL);
	base = ft_strlen(set);
	if (nbr == 0)
		return (ft_strndup("0", -1));
	if (nbr + 1 == -LLONG_MAX)
		return (ft_strndup(LLONG_MIN_S, -1));
	len = ft_nbrlen(nbr, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	while (nbr != 0 && len-- > 0)
	{
		str[len] = set[nbr % base];
		nbr = (LL)(nbr / base);
	}
	return (str);
}

char		*ft_uitoabase(char *set, unsigned long long nbr)
{
	char	*str;
	size_t	base;
	size_t	len;

	if (!set || static_ft_fdset(set))
		return (NULL);
	base = ft_strlen(set);
	if (nbr == 0)
		return (ft_strndup("0", -1));
	len = ft_unbrlen(nbr, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len > 0)
	{
		--len;
		str[len] = set[nbr % base];
		nbr = nbr / base;
	}
	return (str);
}
