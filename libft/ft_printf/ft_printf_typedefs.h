/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPEDEFS_H
# define FT_PRINTF_TYPEDEFS_H

# define PRINTF_FLAGS "+ #"
# define PRINTF_PASIVE_FLAGS "-0"
# define PRINTF_LENGTH1 "htzljqL"
# define PRINTF_LENGTH2 "hl"
# define PRINTF_SN "dDi"
# define PRINTF_FLOAT "fF"
# define PRINTF_STR "sSr"
# define PRINTF_PTR "p"
# define PRINTF_CHR "cC"
# define PRINTF_NDEC "boOxX"
# define PRINTF_USN "uU"
# define PRINTF_CAPL "ucsd"
# define PRINTF_PARCE_CONST ".*"
# define PRINTF_MOD0 "%"
# define PRINTF_MOD3 "\003"

typedef struct				s_printf_buff
{
	char					*buff;
	struct s_printf_buff	*next;
}							t_printf_buff;

typedef struct				s_printf_mods
{
	char					conv;
	int						width;
	int						prec;
	int						prec_spec : 2;
	int						length;
	char					mod0;
	char					*flags;
}							t_printf_mods;

typedef int					(*t_printf_funs)(va_list *args, t_printf_mods mods,
							t_printf_buff *node);

typedef int					(*t_printf_convs)(va_list *args,
							t_printf_mods *mods, t_printf_buff *node,
							t_printf_funs *funs);

#endif
