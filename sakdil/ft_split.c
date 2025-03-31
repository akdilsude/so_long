/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:08:14 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/31 09:10:13 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	i_len(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**frees(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (NULL);
}

static size_t	start_values(size_t i, char c, const char *s)
{
	size_t	start;

	start = i;
	while (s[start] != '\0' && s[start] == c)
		start++;
	return (start);
}

static size_t	end_values(size_t i, char c, const char *s)
{
	size_t	end;

	end = i;
	while (s[end] != '\0' && s[end] != c)
		end++;
	return (end);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	str_i;
	char	**str;

	start = 0;
	str_i = 0;
	str = (char **)malloc(sizeof(char *) * (i_len((char *)s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[start] != '\0')
	{
		start = start_values(start, c, s);
		end = start;
		end = end_values(end, c, s);
		if (str_i == i_len((char *)s, c))
			break ;
		str[str_i] = ft_substr(s, start, end - start);
		if (!str[str_i])
			return (frees(str));
		str_i++;
		start = end;
	}
	str[str_i] = 0;
	return (str);
}
