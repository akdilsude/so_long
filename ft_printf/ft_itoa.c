/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:56:39 by sakdil            #+#    #+#             */
/*   Updated: 2024/12/03 22:57:51 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_itoa(int n)
{
	int		i;
	long	a;
	char	*str;

	a = n;
	i = ft_len(a);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return ('\0');
	if (a == 0)
		str[0] = '0';
	if (a < 0)
	{
		str[0] = '-';
		a = -a;
	}
	str[i--] = '\0';
	while (a > 0)
	{
		str[i--] = (a % 10) + 48;
		a = a / 10;
	}
	i = write(1, str, ft_strlen(str));
	free(str);
	return (i);
}
