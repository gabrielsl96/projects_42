/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:54:53 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/09 10:54:53 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    char *str_temp;
    size_t count;

    str_temp = ((char *) src);
    count = 0;
    while (count < n)
    {
        *((char *) dest + count) = *str_temp + count;
        count++;
    }
    *((char *) dest + count) = '\0';
    return dest;
}