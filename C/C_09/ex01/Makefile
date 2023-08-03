# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <malik.moussouni@proton.me>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 17:21:53 by mmoussou          #+#    #+#              #
#    Updated: 2023/08/02 09:12:04 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft_putchar.c \
	   ./srcs/ft_swap.c \
	   ./srcs/ft_putstr.c \
	   ./srcs/ft_strlen.c \
	   ./srcs/ft_strcmp.c \

OBJS = $(SRCS:.c=.o)

all: libft.a

libft.a: $(OBJS)
	ar -rcs libft.a $(OBJS)

%.o: %.c
	gcc -Werror -Wall -Wextra -I includes/ $< -c -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm libft.a

re: fclean all

.PHONY: all fclean clean re
