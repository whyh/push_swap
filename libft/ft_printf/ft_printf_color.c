/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/08 12:13:33 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_getmod2(char *mod)
{
	if (ft_strncmp(mod, "[greenb", -1))
		return (ft_strndup("\033[42m", -1));
	if (ft_strncmp(mod, "[yellowb", -1))
		return (ft_strndup("\033[43m", -1));
	if (ft_strncmp(mod, "[blueb", -1))
		return (ft_strndup("\033[44m", -1));
	if (ft_strncmp(mod, "[magentab", -1))
		return (ft_strndup("\033[45m", -1));
	if (ft_strncmp(mod, "[cyanb", -1))
		return (ft_strndup("\033[46m", -1));
	if (ft_strncmp(mod, "[whiteb", -1))
		return (ft_strndup("\033[40m", -1));
	return (NULL);
}

static char	*ft_printf_getmod1(char *mod)
{
	if (ft_strncmp(mod, "~]", -1))
		return (ft_strndup("\033[0m", -1));
	if (ft_strncmp(mod, "[bold", -1))
		return (ft_strndup("\033[1m", -1));
	if (ft_strncmp(mod, "[black", -1))
		return (ft_strndup("\033[37m", -1));
	if (ft_strncmp(mod, "[red", -1))
		return (ft_strndup("\033[31m", -1));
	if (ft_strncmp(mod, "[green", -1))
		return (ft_strndup("\033[32m", -1));
	if (ft_strncmp(mod, "[yellow", -1))
		return (ft_strndup("\033[33m", -1));
	if (ft_strncmp(mod, "[blue", -1))
		return (ft_strndup("\033[34m", -1));
	if (ft_strncmp(mod, "[magenta", -1))
		return (ft_strndup("\033[35m", -1));
	if (ft_strncmp(mod, "[cyan", -1))
		return (ft_strndup("\033[36m", -1));
	if (ft_strncmp(mod, "[white", -1))
		return (ft_strndup("\033[30m", -1));
	if (ft_strncmp(mod, "[blackb", -1))
		return (ft_strndup("\033[47m", -1));
	if (ft_strncmp(mod, "[redb", -1))
		return (ft_strndup("\033[41m", -1));
	return (ft_printf_getmod2(mod));
}

static int	ft_printf_findmod(char **mod)
{
	char	*tmp;

	if (!ft_strncmp(*mod, "~]", -1) && !ft_strncmp(*mod, "[bold", -1)
	&& !ft_strncmp(*mod, "[black", -1) && !ft_strncmp(*mod, "[blackb", -1)
	&& !ft_strncmp(*mod, "[red", -1) && !ft_strncmp(*mod, "[redb", -1)
	&& !ft_strncmp(*mod, "[green", -1) && !ft_strncmp(*mod, "[greenb", -1)
	&& !ft_strncmp(*mod, "[yellow", -1) && !ft_strncmp(*mod, "[yellowb", -1)
	&& !ft_strncmp(*mod, "[blue", -1) && !ft_strncmp(*mod, "[blueb", -1)
	&& !ft_strncmp(*mod, "[magenta", -1) && !ft_strncmp(*mod, "[magentab", -1)
	&& !ft_strncmp(*mod, "[cyan", -1) && !ft_strncmp(*mod, "[cyanb", -1)
	&& !ft_strncmp(*mod, "[white", -1) && !ft_strncmp(*mod, "[whiteb", -1))
		return (0);
	tmp = ft_printf_getmod1(*mod);
	ft_strdel(mod);
	*mod = tmp;
	return (1);
}

void		ft_printf_collor(t_printf_buff *node, int i, char *tail, char *mod)
{
	char	*head;
	size_t	i2;

	while (node->buff[++i]
	&& (ft_strin(&(node->buff[i]), '[') || ft_strin(&(node->buff[i]), '~')))
	{
		while (node->buff[i] && node->buff[i] != '~' && node->buff[i] != '[')
			++i;
		head = ft_strndup(node->buff, (size_t)i);
		i2 = (size_t)i + 1;
		while ((node->buff[i2] >= 'a' && node->buff[i2] <= 'z')
		|| node->buff[i2] == ']')
			++i2;
		tail = ft_strndup(&(node->buff[i2]), -1);
		mod = ft_strndup(&(node->buff[i]), i2 - i);
		if (ft_printf_findmod(&mod))
		{
			ft_strninject(&head, mod, -1, -1);
			ft_strdel(&(node->buff));
			node->buff = ft_strjoin(head, tail);
		}
		ft_strdel(&mod);
		ft_strdel(&head);
		ft_strdel(&tail);
	}
}
