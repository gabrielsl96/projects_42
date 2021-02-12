/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:48:57 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/08 13:48:57 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    size_t count;

    count = 0;
    while(count < n)
    {
        *((char *)s + count) = '\0';
        count++;
    }
    *((char *)s + count) = '\0';
}