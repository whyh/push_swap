/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfrepl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:20:17 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/16 22:49:21 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strfrepl(char **buff, char *targ, char *repl, long long field)
{
	long long	i;
	size_t		n;

	if (field < 0)
		field = (long long)ft_strlen(*buff);
	n = ft_strlen(targ);
	while ((i = ft_strnin(*buff, targ, field, -1)) >= 0)
	{
		ft_strneject(buff, targ, (long long)(i + n), n);
		ft_strninject(buff, repl, i, -1);
	}
}
