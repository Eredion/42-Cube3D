# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 09:54:02 by asegovia          #+#    #+#              #
#    Updated: 2020/07/08 08:52:42 by asegovia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cube3D

CFILES = main.c minimap.c movement.c raycast.c sprites.c bmp.c\
		raycast2.c raycast3.c init_structs.c hooks.c

FLAGS = -Wall -Wextra -Werror -lmlx\
	-framework OpenGL -framework Appkit

OBJS = $(CFILES:.c=.o)

MAKE_LIBS = $(MAP) $(LIBFT) $(MLX) 


all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	Make -C Libft
	Make -C map
	Make -C mlx
	gcc $(FLAGS) -o $(NAME) $(OBJS) map/map.a Libft/libft.a

$(MLX):
	Make -C mlx

$(MAP): map/map.a
	Make -C map

$(LIBFT): Libft/libft.a
	Make -C Libft

clean:
	Make -C mlx clean
	Make -C Libft clean
	Make -C map clean
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) map/map.a Libft/libft.a mlx/libmlx.a

re:	fclean $(NAME)

.PHONY:	all clean fclean re
