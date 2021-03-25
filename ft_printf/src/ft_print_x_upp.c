/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:15:39 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 19:18:20 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_upperstr(char *str)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strdup(str);
	while (aux[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	free(aux);
}

void	print_width_x_upp(char *str, t_params *parameters, int len, int *size)
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

void	print_minus_x_upp(char *str, t_params *parameters, int len, int *size)
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

char	*set_string_x_upp(long num, t_params *parameters)
{
	int		i;
	char	*str;
	char	*aux;

	str = ft_dec_to_base(num, 8, 16);
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
	ft_upperstr(aux);
	free(str);
	return (aux);
}

void	ft_print_x_upp(va_list args, t_params *parameters, int *size)
{
	char	*str;
	long	num;
	int		len;

	str = set_string_x_upp(va_arg(args, int), parameters);
	len = ft_strlen(str);
	if (parameters->minus == true)
		print_minus_x_upp(str, parameters, len, size);
	else if (parameters->width == true)
		print_width_x_upp(str, parameters, len, size);
	else
		ft_print_str(str, size);
	free(str);
}
