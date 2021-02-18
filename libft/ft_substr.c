/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:02:39 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/18 09:14:05 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	i;
	size_t	j;

	len_s = ft_strlen(s);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	j = start;
	if (len < len_s)
	{
		while (j < len + start && s[j] != '\0')
		{
			sub[i] = s[j];
			i++;
			j++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
