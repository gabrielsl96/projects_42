/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:17:02 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/02/09 18:17:02 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_isprint(int c)
{
    if(c >= ' ' && c <='~')
        return (1);
    return (0);
}