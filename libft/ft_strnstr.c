/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:50:24 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/11 10:50:24 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t count;
    size_t count_needle;
    size_t len_neddle;

    count = 0;
    len_neddle = ft_strlen(needle);
    if(len_neddle == 0)
        return ((char *) haystack);
    while(haystack[count] != '\0' && count < len)
    {
        count_needle = 0;
        while ((needle[count_needle] != '\0') 
        && (needle[count_needle] == haystack[count + count_needle]))
            count_needle++;
        if (count_needle == len_neddle)
            return (((char *)haystack + count));
        count++;
    }
    return (NULL);
}