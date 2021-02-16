/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:20:52 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/16 17:20:52 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    int count;

    count = 0;
    if (nmemb == 0 || size == 0)
        return (NULL);
    ptr = malloc(nmemb * size);
    while(count < nmemb)
    {
        ptr[count] = 0;
        count++
    }
    return (ptr);
}