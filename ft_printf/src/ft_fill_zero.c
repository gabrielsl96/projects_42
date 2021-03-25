/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:39:30 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 16:20:42 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_fill_zero(char *str, int size)
{
	char	*aux;
	int		zeros;
	int		len;

	zeros = 0;
	len = ft_strlen(str);
	if (len <= size)
		zeros += size - len;
	aux = malloc(sizeof(aux) * (len + zeros + 1));
	ft_memset(aux, '0', zeros);
	ft_memmove(aux + zeros, str, ft_strlen(str));
	aux[zeros + len] = '\0';
	return (aux);
}
