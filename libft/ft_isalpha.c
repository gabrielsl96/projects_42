/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:45:24 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/09 18:45:24 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z'))
    {
        return (1024);
    }
    return (0);
}