# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 14:24:49 by mpitot            #+#    #+#              #
#    Updated: 2023/11/14 14:24:49 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c	\
			ft_toupper.c

BNS		=	ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstsize.c

OBJS	=	${SRCS:.c=.o}

B_OBJS	=	${BNS:.c=.o}

HEADER	=	libft.h

NAME	=	libft.a

CC		=	cc

AR		=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all		:	${NAME}

%.o		:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

bonus	:
	@make SRCS="${SRCS} ${BNS}"

clean	:
	rm -f ${OBJS} ${B_OBJS}

fclean	:	clean
	rm -f ${NAME} ${B_OBJS}

re		:	fclean all

.PHONY	:	all clean fclean re bonus