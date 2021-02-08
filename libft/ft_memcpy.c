/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 21:54:55 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/08 18:58:03 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t count;

    count = 0;
    while (count < n && *((char *) src + count) != '\0')
    {
        *((char *) dest + count) = *((char *) src + count);
        count++;
    }
    return dest;
}