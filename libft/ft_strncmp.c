/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:33:07 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/11 13:33:07 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t count;

    count = 0;
    while (count < n)
    {
        if(s1[count] != s2[count])
        {
            return (s1[count] - s2[count]);
        }
        count++;
    }
    return (0);
}