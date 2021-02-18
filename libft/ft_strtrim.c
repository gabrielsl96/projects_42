/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:32:34 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/18 11:03:58 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1 + start);
	while (end - 1 && ft_strchr(set, s1[end - 1]))
		end--;
	if (!(new = malloc(sizeof(char *) * (end + 1))))
		return (NULL);
	while (start < end)
	{
		new[start] = s1[start];
		start++;
	}
	new[end] = '\0';
	return (new);
}
