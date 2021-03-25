/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:53:13 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 18:12:55 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_width_p(char *str, t_params *parameters, int len, int *size)
{
	int i;

	i = 0;
	i = parameters->value_width;
	while (i - len > 0)
	{
		ft_print_char(' ', size);
		i--;
	}
	ft_print_str(str, size);
}

void	print_minus_p(char *str, t_params *parameters, int len, int *size)
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

char	*fill_zero(char *str, int size)
{
	char	*aux;
	int		zeros;
	int		len;

	zeros = 0;
	len = ft_strlen(str);
	if (len < size)
		zeros += size - len;
	aux = malloc(sizeof(aux) + (len + zeros + 3));
	ft_memmove(aux, "0x", 2);
	ft_memset(aux + 2, '0', zeros);
	ft_memmove(aux + (2 + zeros), str, ft_strlen(str));
	aux[zeros + 2 + len] = '\0';
	return (aux);
}

char	*set_string_p(int num, t_params *parameters)
{
	char	*str;
	char	*aux;
	int		i;

	i = 0;
	if (!num && !parameters->value_precision && parameters->precision)
		str = ft_strdup("");
	else
		str = ft_dec_to_bse_p(num, 16, 16);
	if (parameters->precision == true)
	{
		i = parameters->value_precision;
		aux = fill_zero(str, i);
	}
	else
		aux = ft_strjoin("0x", str);
	free(str);
	return (aux);
}

void	ft_print_p(va_list args, t_params *parameters, int *size)
{
	long long	num;
	char		*str;
	int			i;
	int			len;

	len = 0;
	str = set_string_p(va_arg(args, int), parameters);
	len = ft_strlen(str);
	if (parameters->minus == true || parameters->zero == true)
		print_minus_p(str, parameters, len, size);
	else if (parameters->width == true)
		print_width_p(str, parameters, len, size);
	else
		ft_print_str(str, size);
	free(str);
}
