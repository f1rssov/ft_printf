/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:21:01 by dcompreh          #+#    #+#             */
/*   Updated: 2021/12/27 17:23:52 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h> //va_start, va_arg, va_copy, va_end

int		ft_printstr(char *str);
int		ft_printvoid(unsigned long vd);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char	*s);
int		ft_printdec(int n);
int		ft_uns_int(unsigned int nb);
int		ft_printf(const char *str, ...);
char	*ft_uitoa(unsigned int n);
int		ft_printchar(int c);

#endif