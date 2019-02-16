/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strninject.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 18:36:26 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strninject(char **dst, const char *src, long pos, long n)
{
	char	*head;
	char	*tail;
	char	*inj;
	char	*tmp;

	if (pos < 0)
		pos = ft_strlen(*dst);
	if (n < 0)
		n = ft_strlen(src);
	head = ft_strndup(*dst, pos);
	tail = ft_strndup(&((*dst)[pos]), -1);
	inj = ft_strndup(src, n);
	ft_strdel(dst);
	tmp = ft_strjoin(head, inj);
	ft_strdel(&head);
	ft_strdel(&inj);
	*dst = ft_strjoin(tmp, tail);
	ft_strdel(&tmp);
	ft_strdel(&tail);
}
