/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:41:23 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 11:51:33 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_zero_minus(char *str, int size, char type)
{
	char *aux;
	int zeros;
	int len;
	int signal;

	signal = 0;
	zeros = 0;
	if (str[0] == '-')
		signal++;
	len = ft_strlen(str);
	if (len <= size)
		if (type == '0')
			zeros +=  size - len;
		else
			zeros += size - len + signal;
	aux = malloc(sizeof(aux) + (len + zeros + 1));
	ft_memmove(aux, "-", signal);
	ft_memset(aux + signal, '0', zeros);
	ft_memmove(aux + (signal + zeros), str + signal, len - signal);
	aux[zeros + len] = '\0';
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
	if (*str == '0' && !parameters->value_precision
		&& parameters->precision)
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
			if (parameters->zero && parameters->value_precision < 0
			&& len > 0)
			{
				if (*aux == '-')
				{
					ft_print_char(*aux++, size);
					continue ;
				}
				ft_print_char('0', size);
			}
			else
				ft_print_char(' ', size);
			i--;
		}
		while(*aux != '\0')
			ft_print_char(*aux++, size);
		free(aux - len);
		return ;
	}
	else
		ft_putstr_fd(aux, 1);
	*size += ft_strlen(aux);
	free(aux);
}
