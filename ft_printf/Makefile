# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 16:09:49 by mdesalle          #+#    #+#              #
#    Updated: 2020/12/20 17:08:58 by mdesalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/ft_c_craft.c \
      src/ft_analysis.c \
      src/ft_parser.c \
      src/ft_printf.c \
      src/ft_utilities_one.c \
      src/ft_utilities_two.c \
      src/ft_utilities_three.c \
      src/ft_s_craft.c \
      src/ft_di_craft.c \
      src/ft_u_craft.c \
      src/ft_xx_craft.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -I include -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
