/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:03:16 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:03:16 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	convert(t_main *main)
{
	int	x;
	int	y;

	x = main->sprite->sprite_h;
	y = main->sprite->sprite_w;
	main->sprite->playerr = mlx_xpm_file_to_image(
			main->mlx, "./sprite/right.xpm", &x, &y);
	main->sprite->playerl = mlx_xpm_file_to_image(
			main->mlx, "./sprite/left.xpm", &x, &y);
	main->sprite->yol = mlx_xpm_file_to_image(
			main->mlx, "./sprite/background.xpm", &x, &y);
	main->sprite->duvar = mlx_xpm_file_to_image(
			main->mlx, "./sprite/wall.xpm", &x, &y);
	main->sprite->exit = mlx_xpm_file_to_image(
			main->mlx, "./sprite/exit.xpm", &x, &y);
	main->sprite->coin1 = mlx_xpm_file_to_image(
			main->mlx, "./sprite/coin.xpm", &x, &y);
	main->sprite->coin2 = mlx_xpm_file_to_image(
			main->mlx, "./sprite/coin2.xpm", &x, &y);
}

void	convert_lorr(t_main *main, int move)
{
	int	x;
	int	y;

	x = main->sprite->sprite_h;
	y = main->sprite->sprite_w;
	if (move == 1)
		main->sprite->playerl = mlx_xpm_file_to_image(main->mlx,
				"./sprite/right.xpm", &x, &y);
	if (move == 2)
		main->sprite->playerl = mlx_xpm_file_to_image(main->mlx,
				"./sprite/up.xpm", &x, &y);
	if (move == 3)
		main->sprite->playerl = mlx_xpm_file_to_image(main->mlx,
				"./sprite/down.xpm", &x, &y);
	else if (move == 4)
		main->sprite->playerl = mlx_xpm_file_to_image(main->mlx,
				"./sprite/left.xpm", &x, &y);
}

t_main	*main_init(char *path)
{
	t_main	*main;

	main = (t_main *) malloc(sizeof(t_main));
	main->map = (t_map *) malloc(sizeof(t_map));
	main->sprite = (t_sprite *) malloc(sizeof(t_sprite));
	main->last = 1;
	main->ccount = 0;
	main->mcount = 0;
	main->map->map = map_init(path, main);
	main->mlx = mlx_init();
	convert(main);
	main->win = mlx_new_window(main->mlx,
			main->map->x * PIXEL, main->map->y * PIXEL, TITLE);
	return (main);
}
