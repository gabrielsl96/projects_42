/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:55:24 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/10 10:55:24 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t      ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t count_src;
    size_t count_dest;

    count_src = 0;
    count_dest = 0;
    while (*(dest + count_dest) != '\0')
        count_dest++;
    while (count_src < size && *(src + count_src) != '\0')
    {
        *(dest + count_dest) = *(src + count_src);
        count_src++;
        count_dest++;
    }
    *(dest + count_dest) = '\0';
    return (0);
}