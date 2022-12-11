/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 00:02:26 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/12 00:02:26 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	line_count(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	return (i);
}

int	n_count(char *buffer)
{
	int	i;
	int	enter;

	enter = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}
