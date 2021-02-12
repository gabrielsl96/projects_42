# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsousa-l <gsousa-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 10:18:13 by gsousa-l          #+#    #+#              #
#    Updated: 2021/02/12 10:59:18 by gsousa-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

SRC 	= *.c

OBJS 	= ${SRC:.c=.o}

NAME 	= libft.a

CC 		= gcc
RM 		= rm -f

FLAGS = -Wall -Werror -Wextra

${NAME}:	${OBJS}
			${CC} ${FLAGS} -c ${OBJS}
			${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

so:
	$(CC) -fPIC $(FLAGS) $(SRC)
	gcc -shared -o libft.so $(OBJ)
	