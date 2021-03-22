/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:15:39 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/22 15:49:49 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_upperstr(char *str)
{
	char *aux;
	int i;

	i = 0;
	aux = ft_strdup(str);
	while(aux[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	free(aux);
}

void	ft_print_x_upp(va_list args, t_params *parameters, int *size)
{
	char *str;
	char *aux;
	long num;
	int i;
	int len;

	len = 0;
	num = va_arg(args, int);
	str = ft_dec_to_base(num, 16, 16);
	ft_upperstr(str);
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
