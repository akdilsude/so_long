/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:52:19 by sakdil            #+#    #+#             */
/*   Updated: 2025/04/03 16:28:57 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(ft_len(s1) + ft_len(s2) + 1);
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i] != 0)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

char	*ft_get_read(int fd)
{
	char	*liner;
	char	*str;
	int		rd;

	str = NULL;
	liner = malloc(BUFFER_SIZE + 1);
	if (!liner)
		return (NULL);
	rd = read(fd, liner, BUFFER_SIZE);
	while (rd > 0)
	{
		liner[rd] = '\0';
		str = ft_strjoin(str, liner);
		rd = read(fd, liner, BUFFER_SIZE);
	}
	free(liner);
	return (str);
}

void	name_control(char *str, t_game *list)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.')
			i++;
		else
			break ;
	}
	if ((str[i] == '.' && str[i - 1] == '/')
		|| (ft_strcmp(str + i, ".ber") == 1))
	{
		write(1, "Error\nInvalid map file extension.\n", 34);
		free_exit(list);
	}
}
