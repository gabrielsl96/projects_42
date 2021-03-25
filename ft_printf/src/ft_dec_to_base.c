/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:56:01 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 14:56:03 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long long	max_num(int buffer, int base)
{
	unsigned long long max;

	max = 1;
	while (buffer > 0)
	{
		max *= base;
		buffer--;
	}
	return (max);
}

char		converter_char(unsigned long long num, int base)
{
	if (base == 16)
	{
		if (num == 10)
			return ('a');
		else if (num == 11)
			return ('b');
		else if (num == 12)
			return ('c');
		else if (num == 13)
			return ('d');
		else if (num == 14)
			return ('e');
		else if (num == 15)
			return ('f');
	}
	return (num + 48);
}

int			ft_lendigits(unsigned long long num, int base)
{
	long long	aux;
	int			count;

	aux = num;
	count = 0;
	while (aux > 0)
	{
		aux /= base;
		count++;
	}
	return (count);
}

char		*ft_dec_to_base(long long num, int buffer, int base)
{
	char				*str_aux;
	int					num_digits;
	unsigned long long	num_aux;

	num_digits = 0;
	num_aux = num;
	if (num == 0)
		return (ft_strdup("0"));
	else if (num < 0)
		num_aux = max_num(buffer, base) + num;
	num_digits = ft_lendigits(num_aux, base);
	str_aux = malloc(sizeof(char) * (num_digits + 1));
	str_aux[num_digits--] = '\0';
	while (num_aux > 0)
	{
		str_aux[num_digits] = converter_char(num_aux % base, base);
		num_aux = num_aux / base;
		num_digits--;
	}
	return (str_aux);
}
