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
