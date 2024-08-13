/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:55:42 by dcompreh          #+#    #+#             */
/*   Updated: 2021/12/27 17:20:17 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uns_int(unsigned int nb)
{
	char	*str;
	int		i;

	str = ft_uitoa(nb);
	i = 0;
	if (!str)
	{
		write(1, "(null)", 1);
		free(str);
		str = NULL;
		return (6);
	}
	i = ft_printstr(str);
	free(str);
	return (i);
}

int	ft_hex(unsigned int vd, int g)
{
	int		i;
	char	*arr;

	arr = "0123456789abcdef0123456789ABCDEF";
	i = 1;
	if (vd < 16)
	{
		if (g == 1)
			write(1, &arr[vd + 16], 1);
		else if (g == 0)
			write(1, &arr[vd], 1);
	}
	else
	{
		i += ft_hex((vd / 16), g);
		ft_hex((vd % 16), g);
	}
	return (i);
}

int	ft_printchar(int c)
{
	char	sym;

	sym = (char) c;
	write(1, &sym, 1);
	return (1);
}

int	ft_formats(va_list args, char c)
{
	int	length_print;

	length_print = 0;
	if (c == 'c')
		length_print += ft_printchar(va_arg(args, int));
	else if (c == 's')
		length_print += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
	{
		ft_printstr("0x");
		length_print += ft_printvoid(va_arg(args, unsigned long int)) + 2;
	}
	else if (c == 'd' || c == 'i')
		length_print += ft_printdec(va_arg(args, int));
	else if (c == 'u')
		length_print += ft_uns_int(va_arg(args, unsigned int));
	else if (c == 'x')
		length_print += ft_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		length_print += ft_hex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		length_print += ft_printchar('%');
	return (length_print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length_print;

	i = 0;
	length_print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length_print += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			length_print += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (length_print);
}
