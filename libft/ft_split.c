/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 08:41:55 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/18 09:10:08 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(const char *s1, char c1)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s1[i] == c1)
		i++;
	while (s1[i] && s1[i] != c1)
	{
		len++;
		s1++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = malloc(ft_getlen(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			str[j] = ((char **)s)[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
