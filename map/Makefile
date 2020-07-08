# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asegovia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 11:57:31 by asegovia          #+#    #+#              #
#    Updated: 2020/07/08 09:05:20 by asegovia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = map.a

C_FILES =  map.c get_params.c get_next_line.c map_params.c 

O_FILES = $(C_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:
	gcc -c $(FLAGS) $(C_FILES)
	ar rc $(NAME) $(O_FILES) ../lib/libft.a
	ranlib $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re 
