/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 21:59:06 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/08 18:58:20 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    size_t count_src;
    size_t count_dest;
    
    count_src = 0;
    count_dest = 0;
    while (count_src < n &&*((char *) src + count_src) != '\0')
    {
        if (*((char *) src + count_src) != c)
        {
            *((char *) dest + count_dest) = *((char *) src + count_src);
            count_dest++;
        }
        else
        {
            *((char *) dest + count_dest) = *((char *) src + count_src);
            return dest;
        }
        count_src++;
    }
    return NULL;
}