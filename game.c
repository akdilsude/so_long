/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:30:27 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/31 23:05:31 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	build_window(t_game *list, int height, int width)
{
	list->mlx = mlx_init();
	if (!list->mlx)
	{
		write(1, "Error: MLX build failed\n", 23);
		free_exit(list);
	}
	list->win = mlx_new_window(list->mlx, width, height, "so_long");
	if (!list->win)
	{
		write(1, "Error: Window creation failed\n", 30);
		free_exit(list);
	}
}

static bool	is_move_valid(t_game *list, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= list->x || new_y < 0 || new_y >= list->y)
		return (false);
	if (list->map[new_y][new_x] == '1')
		return (false);
	return (true);
}

static int	exit_game(t_game *list)
{
	if (list->win)
		mlx_destroy_window(list->mlx, list->win);
	if (list->mlx)
	{
		mlx_destroy_display(list->mlx);
		free(list->mlx);
	}
	main_finish(list);
	exit(0);
	return (0);
}

static int	key_control(int keycode, t_game *list)
{
	int	new_x;
	int	new_y;

	new_x = list->player_x;
	new_y = list->player_y;
	if (keycode == 65307)
		exit_game(list);
	if (keycode == 119)
		new_y--;
	if (keycode == 115)
		new_y++;
	if (keycode == 97)
		new_x--;
	if (keycode == 100)
		new_x++;
	if (is_move_valid(list, new_x, new_y))
	{
		list->map[list->player_y][list->player_x] = '0';
		list->player_x = new_x;
		list->player_y = new_y;
		list->map[new_y][new_x] = 'P';
		display_map(list);
	}
	return (0);
}

void	game_start(t_game *list)
{
	int	height;
	int	width;

	height = list->y * 64;
	width = list->x * 64;
	build_window(list, height, width);
	add_images(list);
	display_map(list);
	mlx_hook(list->win, 17, 0, exit_game, list);
	mlx_key_hook(list->win, key_control, list);
	mlx_loop(list->mlx);
}
