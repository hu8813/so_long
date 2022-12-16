/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:57:30 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 20:57:30 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(char *errorcode, t_main *main)
{
	errno = 2;
	perror(errorcode);
	if (main)
		ft_destroy(main);
	exit(0);
}

void	xpm_to_img(t_main *main)
{
	int	x;
	int	y;

	x = main->img->img_h;
	y = main->img->img_w;
	main->img->pr = mlx_xpm_file_to_image(
			main->mlx, "./img/right.xpm", &x, &y);
	main->img->pl = main->img->pr;
	main->img->ple = mlx_xpm_file_to_image(
			main->mlx, "./img/left.xpm", &x, &y);
	main->img->pu = mlx_xpm_file_to_image(
			main->mlx, "./img/up.xpm", &x, &y);
	main->img->pd = mlx_xpm_file_to_image(
			main->mlx, "./img/down.xpm", &x, &y);
	main->img->way = mlx_xpm_file_to_image(
			main->mlx, "./img/way.xpm", &x, &y);
	main->img->wall = mlx_xpm_file_to_image(
			main->mlx, "./img/wall.xpm", &x, &y);
	main->img->exit = mlx_xpm_file_to_image(
			main->mlx, "./img/exit.xpm", &x, &y);
	main->img->coin = mlx_xpm_file_to_image(
			main->mlx, "./img/coin.xpm", &x, &y);
}

t_main	*main_init(char *path)
{
	t_main	*main;

	main = ft_calloc(1, sizeof(t_main));
	main->map = ft_calloc(1, sizeof(t_map));
	main->img = ft_calloc(1, sizeof(t_img));
	main->coincount = 0;
	main->mcount = 0;
	main->map->map = map_init(path, main);
	main->mlx = mlx_init();
	xpm_to_img(main);
	main->win = mlx_new_window(main->mlx,
			main->map->x * PIXEL, main->map->y * PIXEL, "so_long");
	return (main);
}

void	check_files(void)
{
	if (access("img/wall.xpm", F_OK | R_OK) == -1
		|| access("img/way.xpm", F_OK | R_OK) == -1
		|| access("img/coin.xpm", F_OK | R_OK) == -1
		|| access("img/left.xpm", F_OK | R_OK) == -1
		|| access("img/right.xpm", F_OK | R_OK) == -1
		|| access("img/up.xpm", F_OK | R_OK) == -1
		|| access("img/down.xpm", F_OK | R_OK) == -1
		|| access("img/exit.xpm", F_OK | R_OK) == -1)
	{
		errno = 2;
		perror("Error with image file");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_main		*main;

	if (argc != 2 || access(argv[1], F_OK | R_OK) == -1
		|| !ft_strncmp(argv[1] + ft_strlen(argv[1]) - 5, ".ber", 4))
	{
		errno = 2;
		perror("Usage: ./so_long maps/map.ber\nError with map (.ber) file");
		exit(0);
	}
	check_files();
	main = main_init(argv[1]);
	map_check(main);
	draw_map(main);
	mlx_hook(main->win, 2, 1, key_event, main);
	mlx_hook(main->win, CLOSE, 0, ft_destroy, main);
	mlx_loop_hook(main->mlx, render, main);
	mlx_loop(main->mlx);
	return (0);
}
