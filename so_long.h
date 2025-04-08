/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:18:29 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/07 15:04:31 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
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
	int		move_count;
	void	*p_img;
	void	*e_img;
	void	*c_img;
	void	*w_img;
	void	*g_img;
	bool	exit;
}	t_game;

char	*ft_get_read(int fd);
void	name_control(char *str, t_game *list);
void	open_map(char *argv, t_game *list);
size_t	ft_len(const char *s);
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
bool	is_move_valid(t_game *list, int new_x, int new_y);
void	build_window(t_game *list, int height, int width);
int		close_window(t_game *list);
int		exit_game(t_game *list, int win_condition);

#endif