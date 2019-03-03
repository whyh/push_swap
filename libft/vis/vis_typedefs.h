/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:47:32 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 21:10:59 by dderevyn         ###   ########.fr       */
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
# define VIS_GREY 6316128
# define VIS_BRIGHT_GREY 10526880
# define VIS_DARK_GREY 4210752


typedef struct			s_vis2d
{
	int					*img_data;
	int 				x_max;
	int 				y_max;
	double				x0;
	double				y0;
	double				x1;
	double				y1;
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
