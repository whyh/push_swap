/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_gradient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:07:32 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 22:17:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static int		static_get_color(int color0, int color1, double perc)
{
	return ((int)(perc * color1 + color0 * (1 - perc)));
}

static double	static_gradient_percent(int coord, int coord0, int coord1)
{
	double	pos;
	double	perc;
	double	dist;

	dist = coord1 - coord0;
	pos = coord - coord0;
	if (dist == 0)
		perc = 1.0;
	else
		perc = pos / dist;
	return (perc);
}

int				ft_line_gradient(t_vis2d data2d, double sat)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	perc = static_gradient_percent(
	(int)data2d.x, (int)data2d.x0, (int)data2d.x1);
	r = (int)(static_get_color(
	(data2d.rgb0 >> 16), (data2d.rgb1 >> 16), perc) * sat);
	g = (int)(static_get_color(
	(data2d.rgb0 >> 8) & 255, (data2d.rgb1 >> 8) & 255, perc) * sat);
	b = (int)(static_get_color(
	(data2d.rgb0) & 255, (data2d.rgb1) & 255, perc) * sat);
	return ((r << 16) | (g << 8) | b);
}
