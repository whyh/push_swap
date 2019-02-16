/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strneject.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:07:24 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/16 22:47:35 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strneject(char **dst, const char *src, long long field, long long n)
{
	long long	pos;
	char		*head;
	char		*tail;

	if (dst == NULL || *dst == NULL || src == NULL)
		return ;
	if (field < 0)
		field = (long long)ft_strlen(*dst);
	if (n < 0)
		n = (long long)ft_strlen(src);
	while ((pos = ft_strnin(*dst, src, field, n)) != -1)
	{
		head = ft_strndup(*dst, pos);
		tail = ft_strndup(&((*dst)[pos + n]), -1);
		ft_strdel(dst);
		*dst = ft_strjoin(head, tail);
		ft_strdel(&head);
		ft_strdel(&tail);
	}
}
