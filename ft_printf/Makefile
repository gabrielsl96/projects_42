# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 15:47:32 by gsousa-l          #+#    #+#              #
#    Updated: 2021/03/22 13:58:20 by gsousa-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ./libft

LIBFT = libft

CC = gcc

LIB = ar rcs

FLAGS	= -Wall -Werror -Wextra

RM		= rm -f

SRCS	= ft_printf.c \
			src/ft_dec_to_base.c \
			src/ft_utoa.c \
			src/ft_print_var.c \
			src/ft_print_c.c \
			src/ft_print_d_i.c \
			src/ft_print_p.c \
			src/ft_print_s.c \
			src/ft_print_u.c \
			src/ft_print_x.c \
			src/ft_print_x_upp.c \
			src/ft_print_pcnt.c \
			src/ft_print_char.c \
			src/ft_fill_zero.c

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			cp libft/libft.a $(NAME)
			$(LIB) $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT)
			$(RM) $(NAME)

re:			fclean all

teste: 		all
			$(CC) $(FLAGS) ../main_teste.c $(NAME) && ./a.out | cat -e
			rm a.out

.PHONY: all clean fclean re
