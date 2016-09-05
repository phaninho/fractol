# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/04 14:21:39 by stmartin          #+#    #+#              #
#    Updated: 2016/05/08 19:16:28 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft ./minilibx_macos/
LIB_PATH = ./libft/ ./minilibx_macos/

FRAMEWORK = -framework OpenGL -framework Appkit

SRC_NAME = main.c mlx_tools.c put_image.c fractal.c init.c calcul_fractal.c \
		   z_init.c color.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft -lmlx
NAME = fractol

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -Ofast

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
		$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME) $(FRAMEWORK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<
.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C ./libft/
	@echo "\033[37;44m Make minilibx \033[0m"
	@make -C ./minilibx_macos/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	@make -C ./libft/ fclean
	@make -C ./minilibx_macos/ clean

re: fclean
	@$(MAKE) all

norme :
	norminette ./libft/*
	norminette ./src/*
	norminette ./include/*
