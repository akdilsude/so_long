/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:18:29 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/31 22:00:23 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//exit(0) veya exit(1) bak

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct game
{
	char	**map;
	char	**temp;
	char	*line_map;
	void	*mlx;
	void	*win;
	int		c_count;
	int		p_count;
	int		e_count;
	int		fd;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	void	*p_img;
	void	*e_img;
	void	*c_img;
	void	*wall_img;
	void	*ground_img;
}	t_game;

char	*ft_get_read(int fd);
void	name_control(char *str, t_game *list);
void	open_map(char *argv, t_game *list);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	free_exit(t_game *list);
void	game_edit(t_game *list);
void	coordinats_xy(t_game *list);
void	double_free(char **str);
bool	move_control(t_game *list);
void	ft_fill_flood(t_game *list, int x, int y);
void	game_start(t_game *list);
void	main_finish(t_game *list);
void	add_images(t_game *list);
void	display_map(t_game *list);


#endif