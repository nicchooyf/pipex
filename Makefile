# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 19:23:04 by nchoo             #+#    #+#              #
#    Updated: 2022/09/10 21:34:39 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3
LIBFT		=	./libft/libft.a
INCLUDES	=	-I includes
SRC_FILES	=	main.c \
				path.c \
				exec.c \
				utils.c \
				child.c \
				pipe.c
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