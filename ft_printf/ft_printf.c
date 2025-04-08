/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:55:05 by sakdil            #+#    #+#             */
/*   Updated: 2024/12/04 18:20:29 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char type, va_list lst)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_putchar('%');
	else if (type == 'c')
		count += ft_putchar(va_arg(lst, int));
	else if (type == 's')
		count += ft_putstr(va_arg(lst, char *));
	else if (type == 'i' || type == 'd')
		count += ft_itoa(va_arg(lst, int));
	else if (type == 'u')
		count += ft_uns_itoa(va_arg(lst, unsigned int));
	else if (type == 'X')
		count += ft_print_hex(va_arg(lst, unsigned int), 1);
	else if (type == 'x')
		count += ft_print_hex(va_arg(lst, unsigned int), 0);
	else if (type == 'p')
		count += ft_print_pointer(va_arg(lst, unsigned long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	lst;

	va_start(lst, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (count);
			count += ft_check(str[i], lst);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (count);
}
