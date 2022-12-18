/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:55 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:02:55 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	write_move_count(t_main *main)
{
	char	*str;
	char	*str2;
	char	*desc;
	int		c;

	c = 0x00FFFFFF;
	mlx_string_put(main->mlx, main->win, PIXEL * 2, PIXEL / 2, c, "M O V E :");
	if (main->movecount == 0)
		mlx_string_put(main->mlx, main->win, PIXEL * 3, PIXEL / 2, c, "0");
	str = ft_itoa(main->movecount);
	mlx_string_put(main->mlx, main->win, PIXEL * 3, PIXEL / 2, c, str);
	mlx_string_put(main->mlx, main->win, (PIXEL * 4), PIXEL / 2, c, "C O I N:");
	str2 = ft_itoa(main->coincount);
	mlx_string_put(main->mlx, main->win, PIXEL * 5, PIXEL / 2, c, str2);
	desc = "P R E S S   E S C   O R   C L I C K   ( X )   T O   E X I T";
	mlx_string_put(main->mlx, main->win, PIXEL * 8, PIXEL / 2, c, desc);
	free(str);
	free(str2);
}

static int	draw_map2(t_main *main, int i, int j)
{
	if (main->map->map[i][j] == '1')
		mlx_put_image_to_window(main->mlx, main->win,
			main->img->wall, j, i);
	else if (main->map->map[i][j] == '0')
		mlx_put_image_to_window(main->mlx, main->win,
			main->img->way, j, i);
	else if (main->map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(main->mlx, main->win, main->img->pl, j, i);
		main->p_y = i;
		main->p_x = j;
	}
	else if (main->map->map[i][j] == 'E')
		mlx_put_image_to_window(main->mlx, main->win,
			main->img->exitd, j, i);
	else if (main->map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(main->mlx, main->win,
			main->img->coin, j, i);
	}
	else if (main->map->map[i][j] != '\n')
		ft_error("Error \n wrong character", main);
	j++;
	return (j);
}

void	draw_map(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (main->map->y))
	{
		while (j < (main->map->x))
			j = draw_map2(main, i, j);
		i++;
		j = 0;
	}
}
