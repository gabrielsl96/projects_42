/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:09:02 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/09 12:09:02 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t count;

    count = 0;
    while (count < n)
    {
        if (*((char *)s1 + count) != *((char *) s2 + count))
            return (*((char *)(s1 + count)) - *((char *)(s2 + count)));
        count++;
    }
    return (0);
}