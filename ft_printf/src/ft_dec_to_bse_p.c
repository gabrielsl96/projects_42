/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:11:56 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 16:16:04 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long long			ft_max(int buffer, int base)
{
	long long max;

	max = 0;
	while (base-- > 0)
		max *= buffer;
	return (max - 1);
}

static char			convert_hex(int i)
{
	if (i == 10)
		return ('a');
	if (i == 11)
		return ('b');
	if (i == 12)
		return ('c');
	if (i == 13)
		return ('d');
	if (i == 14)
		return ('e');
	if (i == 15)
		return ('f');
	return (i + 48);
}

static long long	negative_tratament(long long n, size_t uint_max)
{
	if (n < 0)
		n = uint_max + n + 1;
	return (n);
}

char				*ft_dec_to_bse_p(unsigned long long n, int buffer, int base)
{
	char	*c;
	char	*str;
	char	*char_temp;
	size_t	uint_max;

	uint_max = ft_max(buffer, base);
	c = ft_calloc(2, sizeof(char));
	str = ft_calloc(2, sizeof(char));
	if (n == 0)
	{
		*str = '0';
		free(c);
		return (str);
	}
	n = negative_tratament(n, uint_max);
	while (n > 0)
	{
		c[0] = convert_hex(n % 16);
		char_temp = str;
		str = ft_strjoin(c, str);
		free(char_temp);
		n = n / 16;
	}
	free(c);
	return (str);
}
