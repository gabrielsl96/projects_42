/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:32:43 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/22 18:32:37 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_char(char c, int *size)
{
	unsigned int ch;

	ch = c;
	ft_putchar_fd(c, 1);
	*size += 1;
}
