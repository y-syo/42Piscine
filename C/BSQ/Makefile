# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 12:51:15 by kiroussa          #+#    #+#              #
#    Updated: 2023/08/01 19:46:00 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsq

LIBFT		= libft.a
LIBFT_SRC 	= libft

SRCS		= src/main.c \
			  src/board_utils.c \
			  src/parser/parser.c \
			  src/parser/read_file.c \
			  src/solver/solver.c \
			  src/verifier/verifier.c \

OBJS		= ${SRCS:.c=.o}

INCLUDE		= include

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
COPTS		= -I ./${INCLUDE} -I ./${LIBFT_SRC}/${INCLUDE} -g

all:	${LIBFT} ${NAME}

.c.o:
	@${CC} ${CFLAGS} ${COPTS} -c $< -o $@

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${COPTS} -o ${NAME} ${OBJS} ${LIBFT_SRC}/${LIBFT}

${LIBFT}:
	@make --no-print-directory -C ${LIBFT_SRC} all

clean:
	@rm -f ${OBJS}
	@make --no-print-directory -C ${LIBFT_SRC} clean

fclean:	clean
	@rm -f ${NAME}
	@make --no-print-directory -C ${LIBFT_SRC} fclean

re:	fclean all

.PHONY:	all clean fclean re
