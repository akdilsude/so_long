/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:30:27 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/02 14:09:11 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	continue_key_control(t_game *list, int new_x, int new_y)
{
	if (is_move_valid(list, new_x, new_y))
	{
		list->map[list->player_y][list->player_x] = '0';
		if (list->exit == true)
		{
			list->map[list->player_y][list->player_x] = 'E';
			list->exit = false;
		}
		list->player_x = new_x;
		list->player_y = new_y;
		if (list->map[list->player_y][list->player_x] == 'E'
			&& list->c_count == 0)
		{
			write(1, "Congratulations you won!\n", 25);
			exit_game(list, 1);
		}
		if (list->map[new_y][new_x] == 'E')
			list->exit = true;
		if (list->map[new_y][new_x] == 'C')
			list->c_count--;
		list->map[new_y][new_x] = 'P';
		list->move_count++;
		ft_printf("Number of movements: %d\n", list->move_count);
		display_map(list);
	}
}

static int	key_control(int keycode, t_game *list)
{
	int	new_x;
	int	new_y;

	new_x = list->player_x;
	new_y = list->player_y;
	if (keycode == 65307)
		exit_game(list, 0);
	else if (keycode == 119)
		new_y--;
	else if (keycode == 115)
		new_y++;
	else if (keycode == 97)
		new_x--;
	else if (keycode == 100)
		new_x++;
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		continue_key_control(list, new_x, new_y);
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
	mlx_hook(list->win, 17, 0, close_window, list);
	mlx_key_hook(list->win, key_control, list);
	mlx_loop(list->mlx);
}
