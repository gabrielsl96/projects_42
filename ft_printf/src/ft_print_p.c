/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:53:13 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/20 16:12:18 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_p(va_list args, t_params *parameters, int *size)
{
	long long num;
	char *str;
	char *aux;

	num = va_arg(args, long long);
	str = ft_dec_to_base(num, 12, 16);
	if(str[0] == 0)
		aux = ft_strdup("(nil)");
	else
		aux = ft_strjoin("0x", str);
	ft_putstr_fd(aux, 1);
	*size += ft_strlen(aux);

}
