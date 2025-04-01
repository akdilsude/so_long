/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:56:43 by sakdil            #+#    #+#             */
/*   Updated: 2024/12/04 18:09:35 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_uns_itoa(unsigned int n)
{
	int		i;
	char	*str;

	i = ft_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return ('\0');
	if (n == 0)
		str[0] = '0';
	str[i--] = '\0';
	while (n > 0)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	i = write(1, str, ft_strlen(str));
	free(str);
	return (i);
}
