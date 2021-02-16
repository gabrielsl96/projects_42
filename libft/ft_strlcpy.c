/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:38:03 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/16 20:15:03 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t count;

	count = 0;
	while (src[count] != '\0' && count < size)
	{
		dest[count] = src[count];
		count++;
	}
	*(dest + count) = '\0';
	return (count);
}
