/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:17:00 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/22 18:48:09 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_lenbr(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	if (nb == 0)
	{
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(long n)
{
	char	*str;
	long	nb;
	int		i;

	nb = n;
	i = ft_lenbr(nb);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}
