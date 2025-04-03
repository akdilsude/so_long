/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:20:39 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/03 16:43:54 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	empty_line_control(t_game *list)
{
	int	i;

	i = 0;
	while (list->line_map[i])
	{
		if (list->line_map[0] == '\n'
			|| (list->line_map[i + 1] && list->line_map[i] == '\n'
				&& list->line_map[i + 1] == '\n')
			|| (list->line_map[i + 1] == '\0' && list->line_map[i] == '\n'))
		{
			write(1, "Error\nMap contains empty line or invalid format.\n", 49);
			free_exit(list);
		}
		i++;
	}
}

static void	map_controller(t_game *list)
{
	int	i;

	i = -1;
	while (list->line_map[++i])
	{
		if (list->line_map[i] == 'P')
			list->p_count++;
		else if (list->line_map[i] == 'E')
			list->e_count++;
		else if (list->line_map[i] == 'C')
			list->c_count++;
		else if (list->line_map[i] != '1' && list->line_map[i] != '0'
			&& list->line_map[i] != '\n')
		{
			write(1, "Error\nInvalid character in map.\n", 32);
			free_exit(list);
		}
	}
	if (list->p_count != 1 || list->e_count != 1 || list->c_count == 0)
	{
		write(1, "Error\nMap must have 1 P, 1 E and at least 1 C.\n", 47);
		free_exit(list);
	}
}

static void	check_map_borders(t_game *list)
{
	int	x;
	int	y;
	int	height;
	int	width;

	height = list->y;
	width = list->x;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if ((y == 0 || y == height - 1 || x == 0 || x == width - 1)
				&& list->map[y][x] != '1')
			{
				write(1, "Error\nMap is not surrounded by walls.\n", 38);
				free_exit(list);
			}
			x++;
		}
		y++;
	}
}

static void	continue_open_map(t_game *list)
{
	coordinats_xy(list);
	check_map_borders(list);
	ft_fill_flood(list, list->player_x, list->player_y);
	if (move_control(list))
	{
		write(1, "Error\nPlayer cannot reach exit or collectibles.\n", 48);
		free_exit(list);
	}
}

void	open_map(char *argv, t_game *list)
{
	list->fd = open(argv, O_RDONLY);
	if (list->fd < 0)
	{
		write(1, "Error\nCannot open map file.\n", 28);
		free_exit(list);
	}
	list->line_map = ft_get_read(list->fd);
	if (!list->line_map)
	{
		write(1, "Error\nFailed to read map file.\n", 31);
		free_exit(list);
	}
	close(list->fd);
	map_controller(list);
	empty_line_control(list);
	list->map = ft_split(list->line_map, '\n');
	list->temp = ft_split(list->line_map, '\n');
	if (!list->map || !list->temp)
	{
		write(1, "Error\nFailed map data.\n", 23);
		free_exit(list);
	}
	continue_open_map(list);
}
