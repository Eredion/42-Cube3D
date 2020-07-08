# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asegovia <asegovia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 12:37:12 by asegovia          #+#    #+#              #
#    Updated: 2020/02/20 14:41:57 by asegovia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FILES = ft_atoi.c ft_isascii.c ft_memcmp.c ft_strlen.c ft_toupper.c\
	ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strncmp.c ft_bzero.c ft_isprint.c\
	ft_memmove.c ft_strnstr.c ft_isalnum.c ft_memccpy.c	ft_memset.c\
	ft_strrchr.c ft_isalpha.c ft_memchr.c ft_strchr.c ft_tolower.c\
	ft_strlcpy.c ft_strjoin.c ft_strlcat.c ft_substr.c ft_strrev.c\
	ft_strjoin.c ft_strtrim.c ft_wordcount.c ft_split.c ft_itoa.c\
	ft_intlen.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_strdup.c ft_calloc.c ft_putstr.c

O_FILES = $(C_FILES:.c=.o)

CBONUS = ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstadd_front_bonus.c\
	 ft_lstmap_bonus.c  ft_lstclear_bonus.c ft_lstnew_bonus.c\
	 ft_lstdelone_bonus.c ft_lstsize_bonus.c ft_lstiter_bonus.c

OBONUS = $(CBONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(C_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

bonus:
	gcc -c $(FLAGS) $(CBONUS) $(C_FILES)
	ar rc $(NAME) $(OBONUS) $(O_FILES)
	ranlib $(NAME)

clean:
	rm -f $(O_FILES) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
