# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 00:02:38 by huaydin           #+#    #+#              #
#    Updated: 2022/12/12 21:22:48 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
SRC = src/main.c src/init.c src/map.c src/draw.c src/event.c src/render.c src/utils.c src/map_check.c
OBJ = main.o init.o map.o draw.o event.o render.o utils.o map_check.o
MLX_DIR = minilibx
FLAGS = -lXext -lX11 -lm -lpthread -ldl -fPIE
MLX = $(addprefix $(MLX_DIR)/,libmlx.a)

.PHONY:		all clean fclean re

all: $(MLX) $(NAME)

$(NAME): $(OBJ) $(MLX)
	@$(CC) -o $@ $? $(FLAGS)
	@mv *.o obj
	@echo done

$(OBJ): $(SRC)
	@cc -c $? -I./minilibx -fPIE

$(MLX):
		 make -C $(MLX_DIR) 
		 
clean:
	@rm -rf obj/*.o
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) 

re: fclean all
