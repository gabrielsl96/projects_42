/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:53:13 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 15:17:00 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_zero(char *str, int size)
{
	char *aux;
	int zeros;
	int len;

	zeros = 0;
	len = ft_strlen(str);
	if(len < size)
		zeros +=  size - len;
	aux = malloc(sizeof(aux) + (len + zeros + 3));
	ft_memmove(aux, "0x", 2);
	ft_memset(aux + 2, '0', zeros);
	ft_memmove(aux + (2 + zeros), str, ft_strlen(str));
	aux[zeros + 2 + len] = '\0';
	return (aux);
}

void	ft_print_p(va_list args, t_params *parameters, int *size)
{
	long long num;
	char *str;
	char *aux;
	int i;
	int len;

	len = 0;
	num = va_arg(args, long long);
	str = ft_dec_to_base_p(num, 16, 16);
	if (((unsigned int)num == 0 || num == NULL) &&
	!parameters->value_precision && parameters->precision)
			str[0] = '\0';
	else if(parameters->precision == true)
	{
		i = parameters->value_precision;
		aux = fill_zero(str, i);
	}
	else
		aux = ft_strjoin("0x", str);
	free(str);
	len = ft_strlen(aux);
	if (parameters->minus == true || parameters->zero == true)
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
