/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:52:59 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/21 10:28:51 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	int		i;

	i = 0;
	i = ft_printf("%%c: %c ", '0' - 256);
	ft_printf(" -> %d\n", i);
	i = ft_printf("%%s: %s ", "lorem");
	ft_printf(" -> %d\n", i);
	i = ft_printf("%%p: %p ", 42);
	ft_printf(" -> %d\n", i);
	i = ft_printf("%%d: %d ", 8);
	ft_printf(" -> %d\n", i);
	i = ft_printf("%%i: %i ", 1234567890);
	ft_printf(" -> %d\n", i);
	i = ft_printf("%%u: %u ", (unsigned int)8);
	ft_printf(" -> %d\n", i);
	i = ft_printf("%%x: %x ", 20000);
	ft_printf(" -> %d\n", i);
	i = ft_printf("%%X: %X ", 20000);
	ft_printf(" -> %d\n", i);
	return (0);
}
