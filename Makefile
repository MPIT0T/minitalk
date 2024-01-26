# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 16:13:23 by mpitot            #+#    #+#              #
#    Updated: 2024/01/26 16:41:09 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 13:26:47 by mbrousse          #+#    #+#              #
#    Updated: 2024/01/26 14:18:56 by mbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERV	=	server.c

SRC_CLN		=	client.c

OBJ_SERV	=	${SRC_SERV:.c=.o}

OBJ_CLN		=	${SRC_CLN:.c=.o}

HEADER		=	project.h

SERVER		=	server

CLIENT		=	client

CC			 =	cc

FLAGS		 =	-Wall -Wextra -Werror

all: ${CLIENT} ${SERVER}

%.o:%.c  ${HEADER} libft/libft.h
	${CC} ${FLAGS} -c $< -o $@

${CLIENT}: ${OBJ_CLN} Makefile
	make -C ./libft
	make -C ./printf
	${CC} ${FLAGS} ${OBJ_CLN} -o ${CLIENT} -L./libft -lft -L./printf -lftprintf

${SERVER}: ${OBJ_SERV} Makefile
	make -C ./libft
	make -C ./printf
	${CC} ${FLAGS} ${OBJ_SERV} -o ${SERVER} -L./libft -lft -L./printf -lftprintf

clean:
	make clean -C ./libft
	make clean -C ./printf
	rm -f ${OBJ_CLN} ${OBJ_SERV}

fclean: clean
	make fclean -C ./libft
	make fclean -C ./printf
	rm -f ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re