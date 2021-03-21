/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:51:24 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/21 14:58:42 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_flags(const char *str, t_params *params, int *len)
{
	while (str[*len] == '-' || str[*len] == '0')
	{
		if (str[*len] == '-')
			params->minus = true;
		else if (str[*len] == '0')
			params->zero = true;
		*len += 1;
	}
}

void	set_width(const char *str, t_params *params, va_list args, int *len)
{
	int value;

	value = 0;
	if (str[*len] == '*')
	{
		params->width = true;
		value = va_arg(args, int);
		if (value < 0)
		{
			params->minus = true;
			value *= -1;
		}
		params->value_width = value;
		*len += 1;
	}
	else
	{
		params->width = true;
		params->value_width = ft_atoi(str + *len);
		while (ft_isdigit(str[*len]))
			*len += 1;
	}
}

void	set_precision(const char *str, t_params *params, va_list args, int *len)
{
	if (str[*len] == '.')
	{
		params->precision = true;
		*len += 1;
		if (str[*len] == '*')
		{
			params->value_precision = va_arg(args, int);
			*len += 1;
		}
		else
		{
			params->value_precision = ft_atoi(str + *len);
			while (ft_isdigit(str[*len]))
				*len += 1;
		}
	}
}

int		print_var(char c, t_params *params, va_list args, int *size)
{
	if (c == 'c')
		ft_print_c(args, params, size);
	else if (c == 's')
		ft_print_s(args, params, size);
	else if (c == 'p')
		ft_print_p(args, params, size);
	else if (c == 'd' || c == 'i')
		ft_print_d_i(args, params, size);
	else if (c == 'u')
		ft_print_u(args, params, size);
	else if (c == 'x')
		ft_print_x(args, params, size);
	else if (c == 'X')
		ft_print_x_upp(args, params, size);
	else if (c == '%')
		ft_print_pcnt(args, params, size);
	else
	{
		*size = -1;
		return (0);
	}
	return (1);
}

int		ft_print_var(const char *str, va_list args, int *size)
{
	t_params	*params;
	int			len;

	len = 0;
	params = malloc(sizeof(params));
	set_flags(str, params, &len);
	set_width(str, params, args, &len);
	set_precision(str, params, args, &len);
	len += print_var(str[len], params, args, size);
	free(params);
	return (len);
}
