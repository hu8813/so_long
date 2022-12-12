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

#include "../audio/miniaudio.h"
#include "../inc/so_long.h"

void	free_func(t_main *main)
{
	if (main->sprite)
		free(main->sprite);
	if (main->map)
		free(main->map);
	if (main->win)
		free(main->win);
	if (main->mlx)
		free(main->mlx);
}

void	write_move_count(t_main *main)
{
	char *str;
	char *str2;

	mlx_string_put(main->mlx, main->win, PIXEL / 3, PIXEL / 2, 0x00FFFFFF,
			"MOVE: ");
	if (main->mcount == 0)
		mlx_string_put(main->mlx, main->win, PIXEL, PIXEL / 2, 0x00FFFFFF,
				"0");
	str = make_number(main->mcount);
	mlx_string_put(main->mlx, main->win, PIXEL, PIXEL / 2, 0x00FFFFFF, str);
	mlx_string_put(main->mlx, main->win, (PIXEL * 2) / 1.5, PIXEL / 2,
			0x00FFFFFF, "COIN: ");
	str2 = make_number(main->ccount);
	mlx_string_put(main->mlx, main->win, PIXEL * 2, PIXEL / 2, 0x00FFFFFF,
			str2);
	free(str);
	free(str2);
}

int	check_ber(char *s)
{
	int l;

	l = ft_strlen(s) - 1;
	if (s[l - 3] == '.' && s[l - 2] == 'b' && s[l - 1] == 'e' && s[l] == 'r')
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_main *main;
	ma_engine audio_engine;

	if (argc != 2 || !check_ber(argv[1]) || access(argv[1], F_OK | R_OK) == -1)
	{
		errno = 2;
		perror("Usage: ./so_long maps/map.ber\nError with map (.ber) file");
		exit(0);
	}
	main = main_init(argv[1]);
	map_check(main);
	ma_engine_init(NULL, &audio_engine);
	ma_engine_play_sound(&audio_engine, "audio/play.mp3", NULL);
	draw_map(main);
	mlx_hook(main->win, 2, 1L << 0, key_event, main);
	mlx_loop_hook(main->mlx, render, main);
	mlx_hook(main->win, 17, 0, ft_key_esc, main);
	mlx_loop(main->mlx);
	free_func(main);
	ma_engine_uninit(&audio_engine);
	return (0);
}
