/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:34:31 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/03 16:55:06 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_images(t_game *list)
{
	int	x;
	int	y;

	list->p_img = mlx_xpm_file_to_image(list->mlx, "textures/p.xpm", &x, &y);
	list->e_img = mlx_xpm_file_to_image(list->mlx, "textures/e.xpm", &x, &y);
	list->c_img = mlx_xpm_file_to_image(list->mlx, "textures/c.xpm", &x, &y);
	list->g_img = mlx_xpm_file_to_image(list->mlx, "textures/g.xpm", &x, &y);
	list->w_img = mlx_xpm_file_to_image(list->mlx, "textures/w.xpm", &x, &y);
	if (!list->p_img || !list->e_img || !list->c_img || !list->g_img
		|| !list->w_img)
	{
		write(1, "Error\nFailed to load game images.\n", 34);
		free_exit(list);
	}
}

static void	place_images(t_game *list, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(list->mlx, list->win, list->g_img, x, y);
	else if (c == '1')
		mlx_put_image_to_window(list->mlx, list->win, list->w_img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(list->mlx, list->win, list->p_img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(list->mlx, list->win, list->c_img, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(list->mlx, list->win, list->e_img, x, y);
}

void	display_map(t_game *list)
{
	int	x;
	int	y;

	y = 0;
	while (y < list->y)
	{
		x = 0;
		while (x < list->x)
		{
			place_images(list, list->map[y][x], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

bool	is_move_valid(t_game *list, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= list->x || new_y < 0 || new_y >= list->y)
		return (false);
	if (list->map[new_y][new_x] == '1')
		return (false);
	return (true);
}

void	build_window(t_game *list, int height, int width)
{
	list->mlx = mlx_init();
	if (!list->mlx)
	{
		write(1, "Error\nMLX build failed.\n", 24);
		free_exit(list);
	}
	list->win = mlx_new_window(list->mlx, width, height, "so_long");
	if (!list->win)
	{
		write(1, "Error\nFailed to create window.\n", 31);
		free_exit(list);
	}
}
