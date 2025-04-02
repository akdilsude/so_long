/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:08:22 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/02 14:31:52 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	continue_exit_game(t_game *list)
{
	if (list->win)
	{
		mlx_destroy_window(list->mlx, list->win);
		list->win = NULL;
	}
	if (list->mlx)
	{
		mlx_destroy_display(list->mlx);
		free(list->mlx);
		list->mlx = NULL;
	}
}

int	exit_game(t_game *list, int win_condition)
{
	if (win_condition == 0)
	{
		write(1, "Out of the game!\n", 17);
	}
	if (list->p_img)
		mlx_destroy_image(list->mlx, list->p_img);
	if (list->c_img)
		mlx_destroy_image(list->mlx, list->c_img);
	if (list->e_img)
		mlx_destroy_image(list->mlx, list->e_img);
	if (list->w_img)
		mlx_destroy_image(list->mlx, list->w_img);
	if (list->g_img)
		mlx_destroy_image(list->mlx, list->g_img);
	list->p_img = NULL;
	list->c_img = NULL;
	list->e_img = NULL;
	list->w_img = NULL;
	list->g_img = NULL;
	continue_exit_game(list);
	main_finish(list);
	exit(0);
	return (0);
}

int	close_window(t_game *list)
{
	exit_game(list, 0);
	return (0);
}
