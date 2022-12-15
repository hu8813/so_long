/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:03:02 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:03:02 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_esc(t_main *main, int key)
{
	int y;

	if (key == ESC)
	{
		mlx_destroy_image(main->mlx, main->img->ple);
		mlx_destroy_image(main->mlx, main->img->pr);
		mlx_destroy_image(main->mlx, main->img->pu);
		mlx_destroy_image(main->mlx, main->img->pd);
		mlx_destroy_image(main->mlx, main->img->wall);
		mlx_destroy_image(main->mlx, main->img->way);
		mlx_destroy_image(main->mlx, main->img->exit);
		mlx_destroy_image(main->mlx, main->img->coin);
		mlx_destroy_window(main->mlx, main->win);
		mlx_destroy_display(main->mlx);
		y = 0;
		while (y < main->map->y)
			free(main->map->map[y++]);
		if (main->map->map)
			free(main->map->map);
		free(main->map);
		free(main->img);
		free(main->audio);
		free(main);
		exit(0);
	}

	if (main->map->map[main->p_y][main->p_x] == 'C')
	{
		main->map->map[main->p_y][main->p_x] = '0';
		main->coincount--;
	}
	return (0);
}

int	key_event(int key, t_main *main)
{
	if (key == W_UP && main->map->map[main->p_y - 1][main->p_x] != '1')
	{
		main->p_y--;
		main->img->pl = main->img->pu;
		printf("move %d\n", ++(main->mcount));
	}
	else if (key == A_LEFT && main->map->map[main->p_y][main->p_x - 1] != '1')
	{
		main->img->pl = main->img->ple;
		main->p_x--;
		printf("move %d\n", ++(main->mcount));
	}
	else if (key == S_DOWN && main->map->map[main->p_y + 1][main->p_x] != '1')
	{
		main->img->pl = main->img->pd;
		main->p_y++;
		printf("move %d\n", ++(main->mcount));
	}
	else if (key == D_RIGHT && main->map->map[main->p_y][main->p_x + 1] != '1')
	{
		main->img->pl = main->img->pr;
		main->p_x++;
		printf("move %d\n", ++(main->mcount));
	}
	return (check_esc(main, key));
}
