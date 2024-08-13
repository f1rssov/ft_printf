/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:35:59 by dcompreh          #+#    #+#             */
/*   Updated: 2021/12/27 17:40:02 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_printvoid(unsigned long vd)
{
	int		i;
	char	*arr;

	arr = "0123456789abcdef0123456789ABCDEF";
	i = 1;
	if (vd < 16)
		write(1, &arr[vd], 1);
	else
	{
		i += ft_printvoid((vd / 16));
		ft_printvoid((vd % 16));
	}
	return (i);
}

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char		*str;
	int			i;
	int			k;

	k = 0;
	i = ft_strlen((char *)s1);
	str = (char *)malloc(i + 1);
	if (NULL == str)
		return (NULL);
	i = 0;
	while (s1[k] != '\0')
	{
		str[i] = s1[k];
		k++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_printdec(int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		free(str);
		str = NULL;
		return (6);
	}
	i = ft_strlen(str);
	ft_printstr(str);
	free(str);
	return (i);
}
