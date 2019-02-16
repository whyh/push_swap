/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:25:21 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/08 21:36:45 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl_typedefs.h"

static int		ft_gnl_del(t_gnl_list *node, t_gnl_list **head)
{
	t_gnl_list	*tmp;

	if (*head == node)
	{
		ft_strdel(&((*head)->buff));
		(*head)->fd = -1;
		return (1);
	}
	tmp = *head;
	while (tmp->next != node)
		tmp = tmp->next;
	tmp->next = node->next;
	if (node->buff)
		ft_strdel(&(node->buff));
	ft_memdel((void**)&node);
	return (1);
}

static int		ft_gnl_valid_n_pull(t_gnl_list **head, char **line, int fd)
{
	t_gnl_data	data;

	if (fd < 0 || !line)
		return (-1);
	data.node = *head;
	*line = ft_strnew(0);
	while (data.node != NULL && data.node->fd != fd)
		data.node = data.node->next;
	if (data.node == NULL)
		return (2);
	data.len = ft_strchr_i(data.node->buff, '\n');
	ft_strninject(line, data.node->buff, -1, data.len);
	if (data.node->buff[data.len] == '\0' && ft_gnl_del(data.node, head))
		return (2);
	if (data.node->buff[data.len] == '\n'
	&& data.node->buff[data.len + 1] == '\0' && ft_gnl_del(data.node, head))
		return (1);
	data.tmp = ft_strndup(&(data.node->buff[data.len + 1]), -1);
	ft_strdel(&(data.node->buff));
	data.node->buff = data.tmp;
	return (1);
}

int				ft_gnl(const int fd, char **line)
{
	static t_gnl_list	*fdl;
	t_gnl_data			data;

	if ((data.ret_flag = ft_gnl_valid_n_pull(&fdl, line, fd)) != 2)
		return (data.ret_flag);
	while ((data.rlen = read(fd, data.rbuff, FT_GNL_BUFF_SIZE)) > 0)
	{
		data.rbuff[data.rlen] = '\0';
		data.len = ft_strchr_i(data.rbuff, '\n');
		ft_strninject(line, data.rbuff, -1, data.len);
		if (data.len != data.rlen && data.len + 1 != data.rlen)
		{
			data.node = (t_gnl_list*)malloc(sizeof(t_gnl_list));
			data.node->buff = ft_strndup(&(data.rbuff[data.len + 1]), -1);
			data.node->fd = fd;
			data.node->next = fdl;
			fdl = data.node;
		}
		if (data.len != data.rlen)
			return (1);
	}
	if (data.rlen < 0)
		return (-1);
	return (**line ? 1 : 0);
}
