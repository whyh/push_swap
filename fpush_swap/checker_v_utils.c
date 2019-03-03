/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:40:53 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 16:20:46 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	push_swap_v_slope(int value, int min, int max)
{
	double	pos;
	double	slope;
	double	dist;

	dist = max - min;
	pos = value - min;
	if (dist == 0)
		slope = 1.0;
	else
		slope = pos / dist;
	return (slope);
}
