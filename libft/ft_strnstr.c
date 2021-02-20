/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:50:24 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/19 22:12:37 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t count;
	size_t count_need;
	size_t len_need;

	count = 0;
	len_need = ft_strlen(needle);
	if (len_need == 0 || len == 0)
		return ((char *)haystack);
	while (haystack[count] && count < len)
	{
		count_need = -1;
		while ((needle[count_need + 1])
				&& (needle[count_need + 1] == haystack[count_need + count + 1]))
			count_need++;
		
		if (count_need == len_need)
			return ((char *)haystack + count);
		count++;
	}
	return (NULL);
}
