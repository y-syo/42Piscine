# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgramati <rgramati@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 08:57:10 by rgramati          #+#    #+#              #
#    Updated: 2023/07/30 10:53:07 by rgramati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libutils.a

SRCS = ./utils/ft_realloc.c \
	   ./utils/ft_atoi.c \
	   ./utils/ft_split.c \
	   ./utils/ft_strlen.c \
	   ./utils/ft_strcpy.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re
