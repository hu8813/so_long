/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:01:48 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:01:48 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_check(t_main *main)
{
	int	i;

	if (main->exitcount <= 0)
		ft_error("Error\nExit not found", main);
	else if (main->coincount <= 0)
		ft_error("Error\nCoin not found", main);
	else if (main->playercount <= 0 || main->playercount > 1)
		ft_error("Error\nPlayer not found or more than one", main);
	i = -1;
	while (++i < main->map->y - 1)
	{
		if (main->map->map[i][0] != '1')
			ft_error("Error\nMAP: (LEFT) border of wall", main);
		else if (main->map->map[i][main->map->x - 1] != '1')
			ft_error("Error\nMAP: (RIGHT) border of wall", main);
	}
	i = -1;
	while (++i < main->map->x)
	{
		if (main->map->map[0][i] != '1')
			ft_error("Error\nMAP: (UP) border of wall", main);
		if (main->map->map[main->map->y - 1][i] != '1')
			ft_error("Error\nMAP: (DOWN) border of wall", main);
	}
}

static char	**map_split2(t_main *main, int height, int width, char *buffer)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	map = ft_calloc((height + 1), sizeof(char *));
	while (y < height)
	{
		x = 0;
		map[y] = ft_calloc((width + 1), sizeof(char));
		while (x < width)
		{
			if (buffer[(y * (width + 1) + x)] == 'E')
				main->exitcount++;
			else if (buffer[y * (width + 1) + x] == 'P')
				main->playercount++;
			else if (buffer[(y * (width + 1) + x)] == 'C')
				main->coincount++;
			map[y][x] = buffer[(y * (width + 1) + x)];
			x++;
		}
		map[y++][x] = '\0';
	}
	return (map);
}

static char	**map_split(char *buffer, t_main *main)
{
	char	**map;
	int		height;
	int		width;
	int		i;

	main->exitcount = 0;
	main->playercount = 0;
	main->coincount = 0;
	height = 0;
	i = 0;
	while (buffer[i] != 0)
		if (buffer[i++] == '\n')
			height++;
	if (buffer[i - 1] != '\n')
		height++;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] && buffer[i] != EOF)
		i++;
	width = i;
	map = map_split2(main, height, width, buffer);
	main->map->x = width;
	main->map->y = height;
	return (map);
}

char	**map_init(char *path, t_main *main)
{
	char	**map;
	char	*buffer;
	int		i;
	int		bytes;
	int		fd;

	buffer = ft_calloc(10000, sizeof(char));
	fd = open(path, O_RDONLY);
	i = 0;
	bytes = 1;
	buffer[0] = '\0';
	while (bytes)
	{
		bytes = read(fd, &buffer[i++], 1);
		if (bytes == -1)
			ft_destroy(main);
	}
	buffer[i] = '\0';
	map = map_split(buffer, main);
	free(buffer);
	close(fd);
	return (map);
}
