# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 00:02:38 by huaydin           #+#    #+#              #
#    Updated: 2022/12/18 03:58:27 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS = -lXext -lX11 -lm -fPIE
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
SRC = src/main.c src/map.c src/draw.c src/event.c src/render.c src/libft_utils.c
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -g3 -O2 -I./inc -I./$(MLX_DIR)

.PHONY:		all clean fclean test re
	 
all: $(MLX) $(NAME) clean

$(NAME): $(OBJ) $(MLX)
	@$(CC) -o $@ $? $(MLX) $(FLAGS) $(CFLAGS)
	@echo Done...
	@echo Usage:    ./so_long maps/map.ber
	@echo or just:  make test
	@echo Controls: press W A S D to move the Player
	
$(OBJ): $(SRC)
	@$(CC) -c $? -I./$(MLX_DIR) -fPIE
	@mv *.o src

$(MLX):
	make -s -C $(MLX_DIR) 

clean:
	@rm -rf src/*.o

fclean: clean
	@rm -rf $(NAME) 

re: fclean all
	@rm -rf src/*.o

test: all
	./so_long maps/map.ber
