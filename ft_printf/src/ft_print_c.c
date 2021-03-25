/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:50:17 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 17:57:47 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_minus_c(char letter, t_params *parameters, int *size)
{
	int i;

	i = parameters->value_width;
	ft_print_char(letter, size);
	while (i - 1 > 0)
	{
		ft_print_char(' ', size);
		i--;
	}
}

void	print_width_c(char letter, t_params *parameters, int *size)
{
	int i;

	i = parameters->value_width;
	while (i - 1 > 0)
	{
		ft_print_char(' ', size);
		i--;
	}
	ft_print_char(letter, size);
}

void	ft_print_c(va_list args, t_params *parameters, int *size)
{
	char	letter;
	int		i;

	i = 0;
	letter = va_arg(args, int);
	if (parameters->minus)
		print_minus_c(letter, parameters, size);
	else if (parameters->width == true)
		print_width_c(letter, parameters, size);
	else
		ft_print_char(letter, size);
}
