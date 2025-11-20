/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:30:51 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/20 14:44:20 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*  FUNCTION: ft_printf                                                       */
/*                                                                            */
/*  Formats and prints its arguments. Handles the following conversions: 	  */
/*	        																  */
/*	• %c Prints a single character.											  */
/*	• %s Prints a string (as defined by the common C convention).			  */
/*	• %p The void * pointer argument has to be printed in hexadecimal format. */
/*	• %d Prints a decimal (base 10) number.									  */
/*	• %i Prints an integer in base 10.										  */
/*	• %u Prints an unsigned decimal (base 10) number.						  */
/*	• %x Prints a number in hexadecimal (base 16) lowercase format.			  */
/*	• %X Prints a number in hexadecimal (base 16) uppercase format.			  */
/*	• %% Prints a percent sign                                                */
/*                                                                            */
/*  @param str  string a print contenant les expressions cspdiuxX%.           */
/*  @param ...  ce qui doit remplacer les expressions.                        */
/*  @return     0 / >0 if failed.                                             */
/*                                                                            */
/*  Example:                                                                  */
/*     ft_printf("(%d, %d)", arr[i], arr[j]);                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// \num    Write a byte whose value is the 1-,
// 			2-, or 3-digit octal number num.
// 			Multibyte characters can be
// 			constructed using multiple \num
// 			sequences.
static int	_print_escape(char c)
{
	if (c == 'a')
		return (_ft_putchar(7));
	else if (c == 'b')
		return (_ft_putchar(8));
	else if (c == 'f')
		return (_ft_putchar(12));
	else if (c == 'n')
		return (_ft_putchar(10));
	else if (c == 'r')
		return (_ft_putchar(13));
	else if (c == 't')
		return (_ft_putchar(9));
	else if (c == 'v')
		return (_ft_putchar(11));
	else if (c == 44)
		return (_ft_putchar(44));
	else if (c == '\\')
		return (_ft_putchar('\\'));
	// else if (c == 'num')
	// 	return (_ft_putchar());
	else
		return (0);
}

/*	• %c Prints a single character.											  */
/*	• %s Prints a string (as defined by the common C convention).			  */
/*	• %p The void * pointer argument has to be printed in hexadecimal format. */
/*	• %d Prints a decimal (base 10) number.									  */
/*	• %i Prints an integer in base 10.										  */
/*	• %u Prints an unsigned decimal (base 10) number.						  */
/*	• %x Prints a number in hexadecimal (base 16) lowercase format.			  */
/*	• %X Prints a number in hexadecimal (base 16) uppercase format.			  */
/*	• %% Prints a percent sign                                                */
static int	_print_ap(char c, va_list ap)
{
	char	*str;

	str = (char *)malloc(sizeof(INT_MAX) * sizeof(char));
	if (c == 'c')
		return (_ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (_ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (_ft_putstr("TODO"));
	else if (c == 'd')
		return (_ft_putnbr(va_arg(ap, int)));
	else if (c == 'i')
		return (_ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (_ft_putnbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (_ft_putstr(_ft_itoa(va_arg(ap, int), str, 16)));
	else if (c == 'X')
		return (_ft_putstr(_ft_toupper(_ft_itoa(va_arg(ap, int), str, 16))));
	else if (c == '%')
		return (_ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += _print_ap(*(++str), ap);
		else if (*str == '\\')
			count += _print_escape(*(++str));
		else
			count += _ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int		i;

	i = 0;
	i = ft_printf("%%c: %c ", 'l');
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
