# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgramati <rgramati@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 14:17:35 by rgramati          #+#    #+#              #
#    Updated: 2023/07/30 16:12:41 by rgramati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = rush-02

LIBP = ./srcs

SRCS = ./srcs/main.c \
	   ./srcs/ft_split_file.c \
	   ./srcs/ft_format.c \
	   ./srcs/ft_displaytab.c \
	   ./srcs/ft_init_dict.c \
	   ./srcs/ft_print_word.c \

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBP) -lutils


lib:
	make re -C $(LIBP)

%.o : %.c $(LIBP)/utils/utils.h
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	make fclean -C $(LIBP)
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re
