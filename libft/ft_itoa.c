/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:46:15 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/18 17:48:06 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lennmb(long nb)
{
	long		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	if (nb == 0)
	{
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;

	num = n;
	i = ft_lennmb(num);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}
/*static int  ft_nmblen(int num)
{
	int count;
	
	count = 0;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	if (num == 0)
		count++;
	while(num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char    *ft_itoa(int n)
{
	int     num_digits;
	char    *str;
	int nb;

	//if (!n)
	  //  return (NULL);
	nb = n;
	num_digits = ft_nmblen(nb);
	if (!(str = (char *)malloc(sizeof(char) * (num_digits + 1))))
		return (NULL);
	str[num_digits] = '\0';
	num_digits--;
	if (nb == 0)
	{
		str[0] = '0';
		return (str) ;
	} 
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (num_digits >= 0)
	{
		str[num_digits] = '0' + (nb % 10);
		nb /= 10;
		num_digits--;
	}
	return (str);
}*/