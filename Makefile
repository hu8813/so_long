# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 09:37:49 by huaydin           #+#    #+#              #
#    Updated: 2023/01/28 09:37:54 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX = minilibx-linux
	EVENT = src/event_linux.c
	MLX_LIB = $(MLX)/libmlx.a
	FLAGS = -lXext -lX11 ./$(MLX)/libmlx.a -I./$(MLX) -L./$(MLX) -lmlx
endif
ifeq ($(UNAME_S),Darwin)
	MLX = minilibx-mac
	EVENT = src/event_mac.c
	FLAGS = -framework OpenGL -framework AppKit -I./$(MLX) -L./$(MLX) -lmlx
endif

NAME = so_long
CC = cc
SRC = src/main.c src/map.c src/draw.c src/render.c src/libft_utils.c \
	src/map_check.c $(EVENT)
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra

.PHONY:		all clean fclean test re

all: $(NAME) clean

$(NAME): $(OBJ)
	@make -s -C $(MLX)
	@$(CC) -o $@ $? $(MLX_LIB) $(FLAGS) $(CFLAGS)
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
