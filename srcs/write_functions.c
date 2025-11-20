/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:37:05 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/20 14:44:53 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	_ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	_ft_putstr(char *str)
{
	int	len;

	len = strlen(str);
	write(1, str, len);
	return (len);
}

int	_ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (count += _ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += _ft_putchar('-');
		n = -n;
	}
	if (n < 10)
	{
		count += _ft_putchar('0' + n);
		return (count);
	}
	else if (n > 9)
	{
		_ft_putnbr(n / 10);
		count += _ft_putchar('0' + (n % 10));
	}
	return (count);
}
