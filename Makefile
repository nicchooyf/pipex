# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 19:23:04 by nchoo             #+#    #+#              #
#    Updated: 2022/09/13 21:35:58 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	pipex
BONUS		:=	pipex_bonus
CC			:=	gcc
CFLAGS		:=	-Wall -Werror -Wextra #-fsanitize=address -g3
LIBFT		:=	libft/libft.a
INCLUDES	:=	-I includes

SRC_DIR		:=	src
OBJ_DIR		:=	obj
SRCS		:=	main.c \
				path.c \
				utils.c \
				child.c \
				pipe.c \
				file.c
SRCS_BONUS	:=	bonus.c \
				path.c \
				utils.c \
				child.c \
				pipe.c \
				file.c
SRCS		:= 	$(SRCS:%=$(SRC_DIR)/%)
SRCS_BONUS	:= 	$(SRCS_BONUS:%=$(SRC_DIR)/%)
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS	:=	$(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM          := rm -f
MAKE        := $(MAKE) --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $^ -o $@
	$(info CREATED $(NAME))

$(BONUS): $(BONUS_OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) $^ -o $@
	$(info CREATED $(BONUS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re bonus
.SILENT: