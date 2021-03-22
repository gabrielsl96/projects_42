/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:50:17 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/22 17:29:21 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_c(va_list args, t_params *parameters, int *size)
{
	char letter;
	int i;

	i = 0;
	letter = va_arg(args, int);
	if(parameters->value_width > 0)
	{
		i = parameters->value_width;
		ft_print_char(letter, size);
		while(i - 1 > 0)
		{
			ft_print_char(' ', size);
			i--;
		}
	}
	else if(parameters->width == true)
	{
		i = parameters->value_width;
		while(i - 1 > 0)
		{
			ft_print_char(' ', size);
			i--;
		}
		ft_print_char(letter, size);
	}
	else
		ft_print_char(letter, size);
}
