/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:00:50 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/07 16:36:50 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	finish_main(t_game *list)
{
	if (list->w_img)
	{
		mlx_destroy_image(list->mlx, list->w_img);
	}
	if (list->g_img)
	{
		mlx_destroy_image(list->mlx, list->g_img);
	}
	if (list->win)
	{
		mlx_destroy_window(list->mlx, list->win);
	}
}

static void	continue_main_finish(t_game *list)
{
	if (list->mlx)
	{
		mlx_destroy_display(list->mlx);
		free(list->mlx);
	}
	if (list->line_map)
	{
		free(list->line_map);
		list->line_map = NULL;
	}
	if (list->fd > 0)
	{
		close(list->fd);
		list->fd = 0;
	}
	if (list->map)
	{
		double_free(list->map);
		list->map = NULL;
	}
	if (list->temp)
	{
		double_free(list->temp);
		list->temp = NULL;
	}
}

void	main_finish(t_game *list)
{
	list->c_count = 0;
	list->e_count = 0;
	list->p_count = 0;
	list->player_x = 0;
	list->player_y = 0;
	list->exit_x = 0;
	list->exit_y = 0;
	list->x = 0;
	list->y = 0;
	if (list->p_img)
	{
		mlx_destroy_image(list->mlx, list->p_img);
	}
	if (list->c_img)
	{
		mlx_destroy_image(list->mlx, list->c_img);
	}
	if (list->e_img)
	{
		mlx_destroy_image(list->mlx, list->e_img);
	}
	finish_main(list);
	continue_main_finish(list);
	free(list);
}

int	main(int argc, char **argv)
{
	t_game	*list;

	list = (t_game *)malloc(sizeof(t_game));
	if (!list)
		return (write(1, "Error\nMalloc failed\n", 20), 0);
	game_edit(list);
	if (argc == 2 && argv[1] && argv[1][0] != '.')
	{
		name_control(argv[1], list);
		open_map(argv[1], list);
		if (list->x > 59 || list->y > 32)
		{
			write(1, "Error\nMap size exceeds limits (max 59x32).\n", 43);
			free_exit(list);
		}
		game_start(list);
	}
	else
	{
		write(1, "Error\nInvalid arguments.\n", 25);
		main_finish(list);
	}
	return (0);
}
