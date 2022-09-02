# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 19:23:04 by nchoo             #+#    #+#              #
#    Updated: 2022/09/02 16:12:34 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
LIBFT		=	./libft/libft.a
INCLUDES	=	-I includes
SRC_FILES	=	main.c \
				path.c \
				exec.c
SRC_DIR		=	src
SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
RM			=	rm

all	:	$(NAME)

$(NAME)	:
		@make -C libft
		@$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT) -o $(NAME)

clean	:
		@$(RM) -f $(OBJ)

fclean	: clean
		@$(RM) -f $(NAME)

re	:	fclean all

.PHONY	:	clean fclean re all