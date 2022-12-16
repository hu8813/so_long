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

static void	render2(t_main *main, int x, int y, int i)
{
	int	j;

	j = 0;
	while (j < main->map->x)
	{
		if (main->map->map[i][j] == '1')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->wall, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == '0' || main->map->map[i][j] == 'P')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->way, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'E')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->exit, j * PIXEL, i * PIXEL);
		else if (main->map->map[i][j] == 'C')
			mlx_put_image_to_window(main->mlx, main->win,
				main->img->coin, j * PIXEL, i * PIXEL);
		j++;
	}
}

int	render(t_main *main)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = main->p_x - 1;
	y = main->p_y - 1;
	while (i < main->map->y)
	{
		render2(main, x, y, i);
		i++;
	}
	mlx_put_image_to_window(main->mlx, main->win, main->img->pl,
		(x + 1) * PIXEL, (y + 1) * PIXEL);
	if (main->coincount == 0
		&& main->map->map[main->p_y][main->p_x] == 'E')
		ft_destroy(main);
	else
		write_move_count(main);
	return (0);
}
