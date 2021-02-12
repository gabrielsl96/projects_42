/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:13:55 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/10 12:13:55 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int count;
    int last;

    count = 0;
    last = -1;
    while (*(s + count) != '\0')
    {
        if (*(s + count) == c)
        {
            last = count;
        }
        count++;
    }
    if (last >= 0)
        return ((char *)s + last);
    return (NULL);
}