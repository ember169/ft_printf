/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:07:57 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/22 09:43:26 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include "libft.a"
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		dispatch_conversion(char c, va_list ap);
int		pf_putchar(char c);
int		pf_putstr(char *str);
int		pf_putnbr(int n);
int		pf_uputnbr(unsigned int n);
size_t	pf_strlen(char *str);
char	*pf_strrev(char *str);
char	*pf_itoa(int n, char *str, int base);
char	*pf_uitoa(unsigned int n, char *str, int base);
char	*pf_toupper(char *str);

#endif
