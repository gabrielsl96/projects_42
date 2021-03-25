/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:56:42 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 18:32:14 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_width_s(char *str, t_params *parameters, int len, int *size)
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

void	print_minus_s(char *str, t_params *parameters, int len, int *size)
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

void	subst_str(char **str, int size)
{
	char *aux;

	aux = ft_strdup(*str);
	if (size < 0)
		size = ft_strlen(*str);
	free(*str);
	*str = ft_substr(aux, 0, size);
	free(aux);
}

char	*set_string_s(char *str, t_params *parameters)
{
	char *aux;

	if (str == NULL)
		aux = ft_strdup("(null)");
	else
		aux = ft_strdup(str);
	if (parameters->precision == true)
		subst_str(&aux, parameters->value_precision);
	return (aux);
}

void	ft_print_s(va_list args, t_params *parameters, int *size)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	str = set_string_s(va_arg(args, char *), parameters);
	len = ft_strlen(str);
	if (parameters->minus == true)
		print_minus_s(str, parameters, len, size);
	else if (parameters->width == true)
		print_width_s(str, parameters, len, size);
	else
		ft_print_str(str, size);
	free(str);
}
