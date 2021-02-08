/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 21:54:55 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/03 22:05:06 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t count;

    count = 0;
    while (count < n)
    {
        *((char *) dest + count) = *((char *) src + count);
        count++;
    }
}