/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:32:34 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/19 18:39:03 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t    len;
    size_t    end;
    char    *new;
    char    *str_temp;
	
	if (!s1 || !set)
        return (NULL);
    str_temp = ft_strnstr(s1, set, strlen(s1));
    if (!str_temp)
      return ((char *)s1);
    len = strlen(str_temp) - 2;
    end = len;
    while (end - 1 && !ft_strnstr(str_temp + end, set, len))
        end--;
    if (len != end)
        len = end;
    if (!(new = malloc(sizeof(char) * (len))))
        return (NULL);
    str_temp++;
    while (--len)
        *new++ = *str_temp++;
    *new = '\0';
	return (new);
}
