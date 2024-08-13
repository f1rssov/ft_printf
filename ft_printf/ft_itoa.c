/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcompreh <dcompreh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:43:23 by dcompreh          #+#    #+#             */
/*   Updated: 2021/12/27 16:38:58 by dcompreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_nbneg(int nb, int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	str[0] = '-';
	nb *= -1;
	while (nb > 0)
	{
		str[len] = 48 + (nb % 10);
		nb /= 10;
		len--;
	}
	return (str);
}

char	*ft_nbplus(int nb, int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nb != 0)
	{
		if (nb < 0)
			nb = -nb;
		str[len] = 48 + (nb % 10);
		nb /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (str = ft_nbneg(n, len));
	return (str = ft_nbplus(n, len));
}
