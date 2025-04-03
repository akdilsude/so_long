/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:20:34 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/03 16:56:41 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_xy(t_game *list)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (list->map[y])
	{
		x = 0;
		while (list->map[y][x])
		{
			if (list->map[y][x] == 'P')
			{
				list->player_x = x;
				list->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	exit_xy(t_game *list)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (list->map[y])
	{
		x = 0;
		while (list->map[y][x])
		{
			if (list->map[y][x] == 'E')
			{
				list->exit_x = x;
				list->exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	coordinats_xy(t_game *list)
{
	int	x;
	int	y;
	int	prev_x;

	prev_x = -1;
	y = 0;
	while (list->map[y] != NULL)
	{
		x = 0;
		while (list->map[y][x] != '\0')
			x++;
		if (prev_x != -1 && x != prev_x)
		{
			write(1, "Error\nMap is not rectangular.\n", 30);
			free_exit(list);
		}
		prev_x = x;
		y++;
	}
	list->x = x;
	list->y = y;
	player_xy(list);
	exit_xy(list);
}

bool	move_control(t_game *list)
{
	int	y;
	int	x;

	y = 0;
	while (list->temp[y])
	{
		x = 0;
		while (list->temp[y][x])
		{
			if ((list->map[y][x] == 'E' || list->map[y][x] == 'C')
				&& list->temp[y][x] != 'F')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

void	ft_fill_flood(t_game *list, int x, int y)
{
	if (x < 0 || y < 0 || y >= list->y || x >= list->x
		|| list->temp[y][x] == '1' || list->temp[y][x] == 'F')
		return ;
	list->temp[y][x] = 'F';
	ft_fill_flood(list, x + 1, y);
	ft_fill_flood(list, x - 1, y);
	ft_fill_flood(list, x, y + 1);
	ft_fill_flood(list, x, y - 1);
}
