# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 00:02:38 by huaydin           #+#    #+#              #
#    Updated: 2022/12/15 21:13:52 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS = -lXext -lX11 -lm -lpthread -ldl -fPIE
	MLX_DIR = minilibx-linux
	MLX = $(MLX_DIR)/libmlx.a
endif
ifeq ($(UNAME_S),Darwin)
	MLX_DIR = minilibx-mac
	FLAGS = -framework OpenGL -framework AppKit -L./$(MLX_DIR) -lmlx -glldb
	MLX = $(MLX_DIR)/libmlx.dylib
endif

NAME = so_long
CC = cc
SRC = src/main.c src/map.c src/draw.c src/event.c src/render.c src/utils.c
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -g3 -O2 -fsanitize=address -I./inc -I./$(MLX_DIR)

.PHONY:		all clean fclean re

all: $(MLX) $(NAME)

$(NAME): $(OBJ) $(MLX)
	@$(CC)  -o $@ $? $(MLX) $(FLAGS)
	@echo Done...
	@echo Usage:   ./so_long maps/map.ber

$(OBJ): $(SRC)
	@cc -c $? -I./$(MLX_DIR) -fPIE
	@mv *.o src

$(MLX):
		 make -s -C $(MLX_DIR) 
		 
clean:
	@rm -rf src/*.o

fclean: clean
	@rm -rf $(NAME) 

re: fclean all
