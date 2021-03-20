/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:15:39 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/20 16:12:18 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_x(va_list args, t_params *parameters, int *size)
{
	int num;
	char *result_hex;

	num = va_arg(args, int);
	result_hex = ft_dec_to_base(num, 8, 16);
	ft_putstr_fd(result_hex, 1);
	*size += ft_strlen(result_hex);
}
