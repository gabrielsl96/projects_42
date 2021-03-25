/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:41:23 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 17:33:16 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_width_d_i(char *str, t_params *parameters, int len, int *size)
{
	int signal;
	int i;

	signal = 0;
	i = parameters->value_width;
	while (i - len > 0)
	{
		if (parameters->zero && parameters->value_precision < 0 && len > 0)
		{
			if (*str == '-')
			{
				ft_print_char(*str, size);
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

void	print_minus_d_i(char *str, t_params *parameters, int len, int *size)
{
	int i;

	i = 0;
	ft_print_str(str, size);
	i = parameters->value_width;
	while (i - len > 0)
	{
		ft_print_char(' ', size);
		i--;
	}
}

char	*fill_zero_minus(char *str, int size, char type)
{
	char	*aux;
	int		zeros;
	int		len;
	int		signal;

	signal = 0;
	zeros = 0;
	if (str[0] == '-')
		signal++;
	len = ft_strlen(str);
	if (len <= size)
	{
		if (type == '0')
			zeros += size - len;
		else
			zeros += size - len + signal;
	}
	aux = malloc(sizeof(aux) + (len + zeros + 1));
	ft_memmove(aux, "-", signal);
	ft_memset(aux + signal, '0', zeros);
	ft_memmove(aux + (signal + zeros), str + signal, len - signal);
	aux[zeros + len] = '\0';
	return (aux);
}

char	*set_string_d_i(int num, t_params *parameters)
{
	char	*str;
	char	*aux;
	int		i;

	i = 0;
	str = ft_itoa(num);
	if (*str == '0' && !parameters->value_precision && parameters->precision)
		str[0] = '\0';
	if (parameters->zero && parameters->precision == false
	&& parameters->minus == false)
	{
		i = parameters->value_width;
		aux = fill_zero_minus(str, i, '0');
	}
	else if (parameters->precision == true)
	{
		i = parameters->value_precision;
		aux = fill_zero_minus(str, i, '-');
	}
	else
		aux = ft_strdup(str);
	free(str);
	return (aux);
}

void	ft_print_d_i(va_list args, t_params *parameters, int *size)
{
	int		num;
	int		i;
	int		len;
	char	*str;

	len = 0;
	str = set_string_d_i(va_arg(args, int), parameters);
	len = ft_strlen(str);
	if (parameters->minus == true)
		print_minus_d_i(str, parameters, len, size);
	else if (parameters->width == true)
		print_width_d_i(str, parameters, len, size);
	else
		ft_print_str(str, size);
	free(str);
}
