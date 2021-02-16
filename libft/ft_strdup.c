/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:14:32 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/16 20:14:10 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int len;
	int count;
	char *dest;

	count = 0;
	len = ft_strlen(s);
	dest = malloc(len + 1);
	while (count < len)
	{
		dest[count] = s[count];
		count++;
	}
	return (dest);
}
