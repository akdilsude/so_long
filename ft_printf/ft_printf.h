/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:55:41 by sakdil            #+#    #+#             */
/*   Updated: 2024/12/04 18:19:58 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(char *str);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_strlen(char *str);
int	ft_itoa(int n);
int	ft_uns_itoa(unsigned int n);
int	ft_print_hex(unsigned long num, int type_upper);
int	ft_print_pointer(unsigned long ptr);

#endif