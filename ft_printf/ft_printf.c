/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:41:46 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/22 17:16:00 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		size;
	int 	len;

	size = 0;
	len = 0;
	va_start(args, str);
	while(str[len] && size >= 0)
	{
		if (str[len] == '%')
		{
			len += ft_print_var(str + len + 1, args, &size);
		}
		else
		{
			ft_putchar_fd(str[len], 1);
			size++;
		}
		len++;
	}
	va_end(args);
	return (size);
}
