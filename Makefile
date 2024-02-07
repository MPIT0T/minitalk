# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:13:23 by mpitot            #+#    #+#              #
#    Updated: 2024/02/07 18:21:43 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERV	=	server.c
SRC_SERV_B	=	server_bonus.c

SRC_CLN		=	client.c
SRC_CLN_B	=	client_bonus.c

OBJ_SERV	=	${SRC_SERV:.c=.o}

OBJ_CLN		=	${SRC_CLN:.c=.o}

HEADER		=	minitalk.h

SERVER		=	server

CLIENT		=	client

CC			 =	cc

FLAGS		 =	-Wall -Wextra -Werror

all:
	make -C ./libft
	make ${CLIENT}
	make ${SERVER}

%.o:%.c  ${HEADER} libft/libft.h libft/libft.a
	${CC} ${FLAGS} -c $< -o $@

${CLIENT}: ${OBJ_CLN} Makefile ${HEADER} libft/libft.a
	${CC} ${FLAGS} ${OBJ_CLN} -o ${CLIENT} -L./libft -lft

${SERVER}: ${OBJ_SERV} Makefile ${HEADER} libft/libft.a
	${CC} ${FLAGS} ${OBJ_SERV} -o ${SERVER} -L./libft -lft

bonus:
	make -C ./libft
	make ${CLIENT} SRC_CLN="${SRC_CLN_B}"
	make ${SERVER} SRC_SERV="${SRC_SERV_B}"

clean:
	make clean -C ./libft
	rm -f ${OBJ_CLN} ${OBJ_SERV}

fclean: clean
	make fclean -C ./libft
	rm -f ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re