/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:34:31 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/02 00:47:47 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_images(t_game *list)
{
	int	x;
	int	y;

	list->p_img = mlx_xpm_file_to_image(list->mlx, "images/p.xpm", &x, &y);
	list->e_img = mlx_xpm_file_to_image(list->mlx, "images/e.xpm", &x, &y);
	list->c_img = mlx_xpm_file_to_image(list->mlx, "images/c.xpm", &x, &y);
	list->ground_img = mlx_xpm_file_to_image(list->mlx, "images/g.xpm", &x, &y);
	list->wall_img = mlx_xpm_file_to_image(list->mlx, "images/w.xpm", &x, &y);
	if (!list->p_img || !list->e_img || !list->c_img || !list->ground_img
		|| !list->wall_img)
	{
		write(1, "Error\n", 6);
		free_exit(list);
	}
}

static void	place_images(t_game *list, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(list->mlx, list->win, list->ground_img, x, y);
	else if (c == '1')
		mlx_put_image_to_window(list->mlx, list->win, list->wall_img, x, y);
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
