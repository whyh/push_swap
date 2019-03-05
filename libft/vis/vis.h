/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:51:21 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/04 22:17:20 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_H
# define VIS_H

# include "../libft.h"
# include <mlx.h>
# include "vis_typedefs.h"

int		ft_line_gradient(t_vis2d data2d, double sat);
void	ft_wu_line(t_vis2d data2d);

#endif
