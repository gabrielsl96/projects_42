/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:15:39 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/20 16:12:18 by gsousa-l         ###   ########.fr       */
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
}

void	ft_print_x_upp(va_list args, t_params *parameters, int *size)
{
	int num;
	char *result_hex;

	num = va_arg(args, int);
	result_hex = ft_dec_to_base(num, 8, 16);
	ft_upperstr(result_hex);
	ft_putstr_fd(result_hex, 1);
	*size += ft_strlen(result_hex);
}
