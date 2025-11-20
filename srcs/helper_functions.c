/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:31:46 by lgervet           #+#    #+#             */
/*   Updated: 2025/11/20 14:44:21 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

size_t	_ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*_ft_strrev(char *str)
{
	size_t	start;
	size_t	end;
	char	tmp;

	start = 0;
	end = _ft_strlen(str) - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		end --;
		start++;
	}
	return (str);
}

char	*_ft_itoa(int n, char *str, int base)
{
	int	i;
	int	is_negative;

	i = 0;
	is_negative = 0;
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		if (base == 10)
			is_negative = 1;
		n = -n;
	}
	while (n != 0)
	{
		if ((n % base) > 9)
			str[i++] = (((n % base) - 10) + 'a');
		else
			str[i++] = ((n % base) + '0');
		n = n / base;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	return (_ft_strrev(str));
}

char	*_ft_toupper(char *str)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((_ft_strlen(str) + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			dest[i] = str[i] - 32;
			i++;
		}
		else
		{
			dest[i] = str[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
