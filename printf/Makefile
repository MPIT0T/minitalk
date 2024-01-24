# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 17:42:43 by mpitot            #+#    #+#              #
#    Updated: 2023/12/20 13:33:03 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c	\
ft_putchar.c	\
ft_putnbr.c		\
ft_putnbr_u.c	\
ft_putstr.c		\
ft_putnbr_x.c	\
ft_putmem.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	ft_printf.h

NAME	=	libftprintf.a

CC		=	cc

AR		=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all		:	${NAME}

%.o		:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

clean	:
	rm -f ${OBJS}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus