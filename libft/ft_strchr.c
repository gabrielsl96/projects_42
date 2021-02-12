/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:07:45 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/10 11:07:45 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_strchr(const char *s, int c)
{
    int count;

    count = 0;
    while (*(s + count) != '\0')
    {
        if (*(s + count) == c)
        {
            return (((char *)s + count));
        }
        count++;
    }
    return (NULL);
}