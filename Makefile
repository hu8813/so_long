# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 00:02:38 by huaydin           #+#    #+#              #
#    Updated: 2023/01/07 15:21:41 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR = minilibx-linux
	FLAGS = -lXext -lX11 -I./$(MLX_DIR) -L./$(MLX_DIR) -lmlx
endif
ifeq ($(UNAME_S),Darwin)
	MLX_DIR = minilibx-mac
	FLAGS = -framework OpenGL -framework AppKit -I./$(MLX_DIR) -L./$(MLX_DIR) -lmlx
endif

NAME = so_long
CC = cc
SRC = src/main.c src/map.c src/draw.c src/event.c src/render.c src/libft_utils.c
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

.PHONY:		all clean fclean test re
	 
all: $(NAME) clean

$(NAME): $(OBJ)
	@make -s -C $(MLX_DIR) 
	@$(CC) -o $@ $? $(FLAGS) $(CFLAGS)
	@echo Done...
	@echo Usage:    ./so_long maps/map.ber
	@echo or just:  make test
	@echo Controls: press W A S D to move the Player

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $?
	@mv *.o src

clean:
	@rm -rf src/*.o

fclean: clean
	@rm -rf $(NAME) 

re: fclean all
	@rm -rf src/*.o

test: all
	./so_long maps/map.ber
