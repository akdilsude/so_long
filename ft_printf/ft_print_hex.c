/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:06 by sakdil            #+#    #+#             */
/*   Updated: 2024/12/04 18:20:57 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long num, int type_upper)
{
	int		count;
	char	*hex_values;

	count = 0;
	if (type_upper)
		hex_values = "0123456789ABCDEF";
	else
		hex_values = "0123456789abcdef";
	if (num >= 16)
		count += ft_print_hex(num / 16, type_upper);
	count += ft_putchar(hex_values[num % 16]);
	return (count);
}
