/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:00:50 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/31 13:35:25 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	}
	else
	{
		write(1, "Error: Bad inputs\n", 18);
		free_exit(list);
	}
	write(1, "ok\n", 3);
	if (list->map)
		double_free(list->map);
	free(list);
	return (0);
}
