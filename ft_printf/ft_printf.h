/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:17:11 by gsousa-l          #+#    #+#             */
/*   Updated: 2021/03/20 16:34:00 by gsousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct 	s_params
{
	bool		minus;
	bool		precision;
	bool		width;
	bool		zero;
	int			value_precision;
	int			value_width;
}				t_params;

int		ft_printf(const char *str, ...);
int		ft_print_var(const char *str, va_list args, int *size);
void	ft_print_c(va_list args, t_params *parameters, int *size);
void	ft_print_s(va_list args, t_params *parameters, int *size);
void	ft_print_p(va_list args, t_params *parameters, int *size);
void	ft_print_d_i(va_list args, t_params *parameters, int *size);
void	ft_print_u(va_list args, t_params *parameters, int *size);
void	ft_print_x(va_list args, t_params *parameters, int *size);
void	ft_print_x_upp(va_list args, t_params *parameters, int *size);
void	ft_print_pcnt(va_list args, t_params *parameters, int *size);
char	*ft_utoa(long n);
char	*ft_dec_to_base(long long num, int buffer, int base);
void	ft_print_char(char c, int *size);
#endif
