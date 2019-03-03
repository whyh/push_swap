/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:10:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/03/03 16:56:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "libft_typedefs.h"
# include "ft_gnl/ft_gnl_typedefs.h"
# include "ft_printf/ft_printf.h"
# include "vis/checker_v.h"

int			ft_gnl(const int fd, char **line);
int			ft_printf(const char *format, ...);
long long	ft_abs(long long nbr);
long long	ft_atoibase(char *set, char *str);
char		*ft_itoabase(char *set, long long nbr);
char		*ft_uitoabase(char *set, unsigned long long nbr);
void		*ft_memalloc(size_t size);
int			ft_memcmp(const void *mem1, const void *mem2, size_t n);
void		ft_memdel(void **memptr);
void		*ft_memmove(void *memdst, const void *memsrc, long size);
void		*ft_memset(void *memptr, unsigned char c, size_t size);
size_t		ft_nbrlen(long long nbr, size_t base);
size_t		ft_unbrlen(unsigned long long nbr, size_t base);
char		*ft_strchr(const char *str, char c);
size_t		ft_strchr_i(const char *str, char c);
void		ft_strdel(char **ptr);
int			ft_strin(const char *str, char c);
char		*ft_strjoin(const char *src1, const char *src2);
size_t		ft_strlen(const char *str);
char		*ft_strncpy(char *dst, const char *src, long n);
char		*ft_strndup(const char *src, long n);
void		ft_strneject(char **dst, const char *src, long long field,
			long long n);
int			ft_strncmp(char const *str1, char const *str2, long n);
char		*ft_strnew(size_t size);
long long	ft_strnin(const char *str, const char *obj, long long field,
			long long n);
void		ft_strninject(char **dst, const char *src, long pos, long n);
void		ft_strfrepl(char **buff, char *targ, char *repl, long long field);
char		*ft_strrchr(const char *str, char c);
void		ft_swap_ll(long long *ptr1, long long *ptr2);
void		ft_swap_i(int *ptr1, int *ptr2);
void		ft_swap_d(double *ptr1, double *ptr2);

#endif
