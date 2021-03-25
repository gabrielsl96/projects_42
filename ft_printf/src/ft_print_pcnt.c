/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pcnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:45:08 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 18:20:57 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_zero_pcnt(int i, t_params *parameters, int *size)
{
	while (i - 1 > 0)
	{
		ft_print_char(' ', size);
		i--;
	}
	ft_print_char('%', size);
}

void	print_width_pcnt(int i, t_params *parameters, int *size)
{
	while (i - 1 > 0)
	{
		ft_print_char('0', size);
		i--;
	}
	ft_print_char('%', size);
}

void	print_minus_pcnt(int i, t_params *parameters, int *size)
{
	ft_print_char('%', size);
	while (i - 1 > 0)
	{
		ft_print_char(' ', size);
		i--;
	}
}

void	ft_print_pcnt(va_list args, t_params *parameters, int *size)
{
	int i;

	i = parameters->value_width;
	if (parameters->minus == true)
		print_minus_pcnt(i, parameters, size);
	else if (parameters->zero == true)
		print_zero_pcnt(i, parameters, size);
	else if (parameters->width == true && parameters->zero == false)
		print_width_pcnt(i, parameters, size);
	else
		ft_print_char('%', size);
}
