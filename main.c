/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:00:50 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/31 20:11:13 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (list->line_map)
		free(list->line_map);
	if (list->fd)
		close(list->fd);
	if (list->map)
		double_free(list->map);
	if (list->temp)
		double_free(list->temp);
	free(list);
}

int	main(int argc, char **argv)
{
	t_game	*list;

	list = (t_game *)malloc(sizeof(t_game));
	if (!list)
		return (write(1, "Error\n", 6), 0);
	if (argc == 2 && argv[1] && argv[1][0] != '.')
	{
		game_edit(list);
		name_control(argv[1], list);
		open_map(argv[1], list);
		if (list->x > 40 || list->y > 21)
		{
			write(1, "Error: Wrong size\n", 18);
			free_exit(list);
		}
		game_start(list);
	}
	else
	{
		write(1, "Error: Bad inputs\n", 18);
		main_finish(list);
	}
	return (0);
}
