/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:41:23 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/22 10:57:25 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_zero_minus(char *str, int size)
{
	char *aux;
	int zeros;
	int len;
	int signal;

	signal = 0;
	len = ft_strlen(str);
	zeros = 0;
	if (str[0] == '-')
		signal++;
	if (len < size)
		zeros +=  size - len + signal;
	aux = malloc(sizeof(aux) + (len + zeros + signal + 1));
	ft_memmove(aux, "-", signal);
	ft_memset(aux + signal, '0', zeros );
	ft_memmove(aux + (signal + zeros), str + signal, len - signal);
	aux[zeros + signal + len] = '\0';
	return (aux);
}

void	ft_print_d_i(va_list args, t_params *parameters, int *size)
{
	int num;
	int i;
	int len;
	char *str;
	char *aux;

	len = 0;
	num = va_arg(args, int);
	str = ft_itoa(num);
	if (parameters->zero && parameters->precision == false
	&& parameters->minus == false)
	{
		i = parameters->value_width;
		aux = fill_zero_minus(str, i);
	}
	else if (parameters->precision == true)
	{
		i = parameters->value_precision;
		aux = fill_zero_minus(str, i);
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
