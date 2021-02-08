/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:48:46 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/03 18:12:37 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    *ft_memset(void *s, int c, size_t n)
{
    size_t count;

    count = 0;
    while (count < n)
    {
        *((char*)s + count) = (char)c;
        count++;
    }
    *((char*)s + count) = (char)c;
    return (s);
}
