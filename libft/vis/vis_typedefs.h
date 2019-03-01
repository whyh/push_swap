/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:47:32 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/27 18:50:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_TYPEDEFS_H
# define VIS_TYPEDEFS_H

# include "../libft.h"
# include "math.h"

# define VIS_MUSTARD_YELLOW 10066176
# define VIS_MAGMA_RED 9972992
# define VIS_BG_GREY 2105376
# define VIS_WHITE 16777215


typedef struct			s_vis2d
{
	int					*img_data;
	int 				x_max;
	int 				y_max;
	int					x0;
	int 				y0;
	int 				x1;
	int					y1;
	int					rgb0;
	int					rgb1;
	int					r;
	int					rv;
	double				x;
	double 				y;
	double				dx;
	double				dy;
	double				slope;
}						t_vis2d;

#endif
