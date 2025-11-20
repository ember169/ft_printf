/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:07:57 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/20 14:43:29 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

// # include "libft.a"
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		_ft_putchar(char c);
int		_ft_putstr(char *str);
int		_ft_putnbr(int n);
char	*_ft_itoa(int n, char *str, int base);
char	*_ft_toupper(char *str);

#endif