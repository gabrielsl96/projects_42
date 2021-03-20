/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:32:28 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/19 11:23:24 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_u(va_list args, t_params *parameters, int *size)
{
	long num;
	long max_num32bits;
	char *aux;

	num = va_arg(args, int);
	max_num32bits = 4294967296;
	if(num < 0)
	{
		num = 4294967296 + num;
	}
	aux = ft_utoa(num);
	ft_putstr_fd(aux, 1);
	*size += ft_strlen(aux);
}
