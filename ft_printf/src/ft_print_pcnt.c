/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pcnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:45:08 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/22 09:37:11 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_pcnt(va_list args, t_params *parameters, int *size)
{
	int i;

	i = 0;
	if(parameters->minus == true)
	{
		i = parameters->value_width;
		ft_print_char('%', size);
		while(i - 1 > 0)
		{
			ft_print_char(' ', size);
			i--;
		}
	}
	else if(parameters->width == true && parameters->zero == false)
	{
		i = parameters->value_width;
		while(i - 1 > 0)
		{
			ft_print_char(' ', size);
			i--;
		}
		ft_print_char('%', size);
	}
	else
		ft_print_char('%', size);
}
