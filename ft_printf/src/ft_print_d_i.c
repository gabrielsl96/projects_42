/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:41:23 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/19 10:08:44 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_d_i(va_list args, t_params *parameters, int *size)
{
	int num;
	char *aux;

	num = va_arg(args, int);
	aux = ft_itoa(num);
	ft_putstr_fd(aux, 1);
	*size += ft_strlen(aux);

}
