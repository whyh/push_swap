/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wu_line_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:38:51 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 16:56:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_v.h"

static void	static_draw_p(t_vis2d *data2d, double x, double y, double sat)
{
	int point;

	if (sat <= 0.3)
		sat = 0.4;
	else if (sat <= 0.4)
		sat = 0.6;
	else if (sat <= 0.5)
		sat = 0.8;
	point = (int)x + ((int)y * data2d->x_max);
	if ((int)y < data2d->y_max && (int)x < data2d->x_max)
		data2d->img_data[point] = ft_line_gradient(*data2d, sat);
}

static void	static_init_line(t_vis2d *data)
{
	data->rv = 0;
	if ((data->y1 - data->y0) > (data->x1 - data->x0))
	{
		ft_swap_d(&(data->y0), &(data->x0));
		ft_swap_d(&(data->y1), &(data->x1));
		data->rv = 1;
	}
	if (data->x1 < data->x0)
	{
		ft_swap_d(&(data->x0), &(data->x1));
		ft_swap_d(&(data->y0), &(data->y1));
	}
	data->dx = data->x1 - data->x0;
	data->dy = data->y1 - data->y0;
	data->slope = data->dy / data->dx;
	data->x = data->x0;
	data->y = data->y0;
}

void		ft_wu_line(t_vis2d data)
{
	static_init_line(&data);
	while (data.x <= data.x1)
	{
		if (data.rv == 0)
		{
			static_draw_p(&data, data.x, data.y, 1 - (data.y - (int)data.y));
			static_draw_p(&data, data.x, data.y + 1, data.y - (int)data.y);
		}
		else if (data.rv == 1)
		{
			static_draw_p(&data, data.y, data.x, 1 - (data.y - (int)data.y));
			static_draw_p(&data, data.y + 1, data.x, data.y - (int)data.y);
		}
		data.x++;
		data.y += data.slope;
	}
}

void	ft_wu_circle(t_vis2d data)
{
	data.x = -data.r;
	data.y = 0;
	while (data.y > data.x)
	{
		data.x = sqrt(data.r * data.r - data.y * data.y);
		data.slope = data.x - (int)(data.x);
		data.dx =(int)(data.x - data.slope);
		static_draw_p(&data, data.dx + data.x0, data.y + data.y0, 1 - data.slope);
		static_draw_p(&data, data.dx + 1 + data.x0, data.y + data.y0, data.slope);
		data.y--;
	}
}
