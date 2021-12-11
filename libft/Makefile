# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 16:26:28 by mpezzull          #+#    #+#              #
#    Updated: 2021/05/20 16:35:51 by mpezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
NAME	=	libft.a
INCLUDE = 	libft.h
FILES	=	./*.c
COMPILED	=	 $(FILES:.c=.o)
all: $(NAME)
$(NAME):
	@gcc -c $(FLAGS) $(FILES)
	@ar -rc $(NAME) $(COMPILED)
clean:
	@($(RM) $(COMPILED))
fclean: clean
	@($(RM) $(NAME))
re: fclean all