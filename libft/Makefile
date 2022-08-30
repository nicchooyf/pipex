# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 17:21:26 by nchoo             #+#    #+#              #
#    Updated: 2022/08/17 15:39:02 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar rcs
RM		=	rm

INCLUDES	= 	-I includes
SRC_PATH	=	src
OBJ_PATH	=	obj
SUBDIR		=	gnl libft printf


SRC_DIR	= $(foreach dir, $(SUBDIR), $(addprefix $(SRC_PATH)/, $(dir)))
OBJ_DIR	= $(foreach dir, $(SUBDIR), $(addprefix $(OBJ_PATH)/, $(dir)))
SRC		= $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ		= $(subst $(SRC_PATH), $(OBJ_PATH), $(SRC:.c=.o))

$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c
					@mkdir -p $(OBJ_PATH) $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all	:	$(NAME)

$(NAME)	:	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

clean	:
			@$(RM) $(OBJ)
			@$(RM) -rf $(OBJ_PATH)

fclean	:	clean
			@$(RM) $(NAME)

re	:		fclean all

.PHONY	:	all clean fclean re