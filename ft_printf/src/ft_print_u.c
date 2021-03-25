/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:32:28 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 12:12:35 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	converter_unsigned(long *num)
{
	long max_num;

	max_num = 4294967296;
	if(*num < 0)
	{
		*num = 4294967296 + *num;
	}
}

void	ft_print_u(va_list args, t_params *parameters, int *size)
{
	char *str;
	char *aux;
	long num;
	int i;
	int len;

	len = 0;
	num = va_arg(args, int);
	converter_unsigned(&num);
	str = ft_utoa(num);
	if (*str == '0' && !parameters->value_precision
		&& parameters->precision)
			str[0] = '\0';
	if (parameters->zero && parameters->precision == false
	&& parameters->minus == false)
	{
		i = parameters->value_width;
		aux = ft_fill_zero(str, i);
	}
	else if (parameters->precision == true)
	{
		i = parameters->value_precision;
		aux = ft_fill_zero(str, i);
	}
	else
		aux = ft_strdup(str);
	free(str);
	len = ft_strlen(aux);
	if (parameters->minus == true)
	{
		ft_putstr_fd(aux, 1);
		i = parameters->value_width;
		while(i - len > 0)
		{
			ft_print_char(' ', size);
			i--;
		}
	}
	else if (parameters->width == true)
	{
		i = parameters->value_width;
		while(i - len > 0)
		{
			ft_print_char(' ', size);
			i--;
		}
		ft_putstr_fd(aux, 1);
	}
	else
		ft_putstr_fd(aux, 1);
	*size += ft_strlen(aux);
	free(aux);
}
