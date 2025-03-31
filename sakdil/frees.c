/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:52:08 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/31 13:08:42 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	double_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
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
	if (list->line_map)
		free(list->line_map);
	if (list->fd)
		close(list->fd);
	if (list->map)
		double_free(list->map);
	exit(1);
}

void	game_edit(t_game *list)
{
	list->line_map = NULL;
	list->map = NULL;
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
}
