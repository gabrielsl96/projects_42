/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:56:42 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/25 15:06:43 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

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

void	ft_print_s(va_list args, t_params *parameters, int *size)
{
	char *str;
	char *aux;
	int i;
	int str_len;

	str_len = 0;
	str = va_arg(args, char *);
	if(str == NULL)
		aux = ft_strdup("(null)");
	else
		aux = ft_strdup(str);
	if (parameters->precision == true)
	{
		i = parameters->value_precision;
		subst_str(&aux, i);
	}
	str_len = ft_strlen(aux);
	if(parameters->minus == true)
	{
		i = parameters->value_width;
		ft_putstr_fd(aux, 1);
		while((i - str_len) > 0)
		{
			ft_print_char(' ', size);
			i--;
		}
	}
	else if(parameters->width == true)
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
