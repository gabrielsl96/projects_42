/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:55:24 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/16 10:02:20 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t      ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t count_src;
    size_t count_dest;

    count_src = 0;
    count_dest = ft_strlen(dest);
	if (size < count_dest)
		return (ft_strlen(src) + size);
    while ((count_dest + 1) < size && src[count_src])
    {
        *(dest + count_dest) = *(src + count_src);
        count_src++;
        count_dest++;
    }
    *(dest + count_dest) = '\0';
    return (count_src + count_dest);
}
