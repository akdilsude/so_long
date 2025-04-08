/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:52:08 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/02 14:31:26 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	double_free(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
}

static void	continue_free_exit(t_game *list)
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

void	free_exit(t_game *list)
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
		mlx_destroy_image(list->mlx, list->p_img);
	if (list->c_img)
		mlx_destroy_image(list->mlx, list->c_img);
	if (list->e_img)
		mlx_destroy_image(list->mlx, list->e_img);
	if (list->w_img)
		mlx_destroy_image(list->mlx, list->w_img);
	if (list->g_img)
		mlx_destroy_image(list->mlx, list->g_img);
	if (list->win)
		mlx_destroy_window(list->mlx, list->win);
	continue_free_exit(list);
	free(list);
	exit(1);
}

void	game_edit(t_game *list)
{
	list->line_map = NULL;
	list->map = NULL;
	list->temp = NULL;
	list->win = NULL;
	list->mlx = NULL;
	list->e_img = NULL;
	list->c_img = NULL;
	list->p_img = NULL;
	list->w_img = NULL;
	list->g_img = NULL;
	list->c_count = 0;
	list->p_count = 0;
	list->e_count = 0;
	list->fd = 0;
	list->x = 0;
	list->y = 0;
	list->player_x = 0;
	list->player_y = 0;
	list->exit_x = 0;
	list->exit_y = 0;
	list->move_count = 0;
	list->exit = false;
}
