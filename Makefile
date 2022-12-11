# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 00:02:38 by huaydin           #+#    #+#              #
#    Updated: 2022/12/12 00:02:39 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_b
CC = gcc
SRC = src/main.c src/init.c src/map.c src/draw.c src/event.c src/render.c src/utils.c src/map_check.c src/utils2.c
OBJ = main.o init.o map.o draw.o event.o render.o utils.o map_check.o utils2.o
BSRC = bonus/b_main.c bonus/b_init.c bonus/b_map.c bonus/b_draw.c bonus/b_event.c bonus/b_render.c bonus/b_utils.c bonus/*.c bonus/b_map_check.c bonus/b_utils2.c
BOBJ = b_main.o b_init.o b_map.o b_draw.o b_event.o b_render.o b_utils.o b_map_check.o b_utils2.o
FLAGS = -L./minilibx -lmlx -L$(INCLIB) -lXext -lX11 -lm

all: $(NAME)

INC=%%%%

INCLIB=$(INC)/minilibx/lib

$(NAME): $(OBJ)
	@$(CC) -o $@ $? $(FLAGS)
	@mv *.o obj
	@echo done

$(OBJ): $(SRC)
	@gcc -c $? -I inc

bonus: $(BNAME)

$(BNAME): $(BOBJ)
	@$(CC) -o $@ $? $(FLAGS)
	@mv *.o obj
	@echo done

$(BOBJ): $(BSRC)
	@gcc -c $? -I inc

clean:
	@rm -rf $(NAME) $(BNAME)

fclean:
	@rm -rf obj/*.o

re: fclean all
