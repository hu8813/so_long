/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:01:58 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:01:58 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	render2(t_main *main, int y)
{
	int	x;

	x = 0;
	while (x < main->map->x)
	{
		if (main->map->map[y][x] == '1')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->wall, x * PIXEL, y * PIXEL);
		else if (main->map->map[y][x] == '0' || main->map->map[y][x] == 'P')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->way, x * PIXEL, y * PIXEL);
		else if (main->map->map[y][x] == 'E')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->exitd, x * PIXEL, y * PIXEL);
		else if (main->map->map[y][x] == 'C')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->coin, x * PIXEL, y * PIXEL);
		x++;
	}
}

int	render(t_main *main)
{
	int	y;

	y = 0;
	while (y < main->map->y)
	{
		render2(main, y);
		y++;
	}
	mlx_put_image_to_window(main->mlx, main->win, main->img->pl,
		(main->p_x) * PIXEL, (main->p_y) * PIXEL);
	if (main->coincount == 0
		&& main->map->map[main->p_y][main->p_x] == 'E')
		ft_destroy(main);
	else
		write_move_count(main);
	return (0);
}
