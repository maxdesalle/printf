# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 16:09:49 by mdesalle          #+#    #+#              #
#    Updated: 2021/01/25 11:51:36 by mdesalle         ###   ########.fr        #
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
      src/ft_di_craft.c \
      src/ft_u_craft.c \
      src/ft_xx_craft_one.c \
      src/ft_xx_craft_two.c \
      src/ft_p_craft.c \
      src/ft_percent_craft.c \
      src/ft_s_craft.c

ccgreen = "\033[0;92m"

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I include -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@printf $(ccgreen)
	@echo "Library successfully compiled"

clean:
	rm -rf $(OBJ)
	@printf $(ccgreen)
	@echo "Library successfully cleaned"
	
fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	@printf $(ccgreen)
	@echo "Library successfully cleaned, including the libftprintf.a file"

fcleanre:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fcleanre all
