/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:32:28 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 19:12:42 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_width_u(char *str, t_params *parameters, int len, int *size)
{
	int signal;
	int i;

	signal = 0;
	i = parameters->value_width;
	while (i - len > 0)
	{
		if (parameters->zero && parameters->value_precision < 0 && len > 0)
		{
			if (str[0] == '-' && signal == 0)
			{
				ft_print_char('-', size);
				signal = 1;
				continue ;
			}
			ft_print_char('0', size);
		}
		else
			ft_print_char(' ', size);
		i--;
	}
	ft_print_str(str + signal, size);
}

void	print_minus_u(char *str, t_params *parameters, int len, int *size)
{
	int i;

	i = parameters->value_width;
	ft_print_str(str, size);
	while (i - len > 0)
	{
		ft_print_char(' ', size);
		i--;
	}
}

void	converter_unsigned(long *num)
{
	if (*num < 0)
	{
		*num = 4294967296 + *num;
	}
}

char	*set_string_u(long num, t_params *parameters)
{
	int		i;
	char	*str;
	char	*aux;

	str = ft_utoa(num);
	if (*str == '0' && !parameters->value_precision && parameters->precision)
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
	return (aux);
}

void	ft_print_u(va_list args, t_params *parameters, int *size)
{
	char	*str;
	long	num;
	int		len;

	num = va_arg(args, int);
	converter_unsigned(&num);
	str = set_string_u(num, parameters);
	len = ft_strlen(str);
	if (parameters->minus == true)
		print_minus_u(str, parameters, len, size);
	else if (parameters->width == true)
		print_width_u(str, parameters, len, size);
	else
		ft_print_str(str, size);
	free(str);
}
