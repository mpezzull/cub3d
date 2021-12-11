# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 18:16:24 by mpezzull          #+#    #+#              #
#    Updated: 2021/05/11 18:16:24 by mpezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror 

SRCS		= 	raycasting/*.c \
			get_next_line/*.c \
			libft/*.c \
			get_map_data/*.c \
			main.c

LIBS =  -lmlx -framework OpenGL -framework AppKit\
	   ./libft/libft.a

all: $(NAME)

$(NAME):
	@(make re -C libft/)
	@(gcc $(FLAGS) $(SRCS) $(LIBS) -o $(NAME))

clean:
	@(make clean -C ./libft/)

fclean:	clean
	@(make fclean -C ./libft/)
	@(rm -rf $(NAME))
	@(rm -f *.bmp)

re: fclean all

.PHONY: re, clean, fclean, all
