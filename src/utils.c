/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:12 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:02:12 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	recursive(int number, int *index, char *str)
{
	if (number)
	{
		recursive(number / 10, index, str);
		str[(*index)] = (number % 10) + '0';
		(*index)++;
		str[(*index)] = '\0';
	}
}

int	draw_first_line(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->map->x / 2)
	{
		mlx_put_image_to_window(main->mlx, main->win,
			main->sprite->duvar, i * PIXEL, 0);
		i++;
	}
	return (0);
}

char	*make_number(int number)
{
	char	*str;
	int		tmp;
	int		len;

	tmp = number;
	len = 0;
	str = malloc(sizeof(char) * 50);
	if (number == 0)
	{
		str[0] = number + '0';
		return (str);
	}
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	free(str);
	str = (char *) malloc(sizeof(char) * (len + 1));
	len = 0;
	recursive(number, &len, str);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_key_esc(t_main *game)
{
	mlx_destroy_image(game->mlx, game->win);
	exit(0);
	return (0);
}
