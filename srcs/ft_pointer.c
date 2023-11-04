/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:14:13 by mvpee             #+#    #+#             */
/*   Updated: 2023/11/04 17:09:12 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_pointer_address(size_t x, char *base)
{
	char	string[25];
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
	while (x != 0)
	{
		string[i++] = base[x % 16];
		x = x / 16;
	}
	while (i--)
	{
		temp = ft_putchar_fd_l(string[i], 1);
		if (temp < 0)
			return (-1);
		len += temp;
	}
	return (len);
}

int	ft_pointer(size_t x)
{
	char	base[17];
	int		len;
	int		result;

	ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (write(1, "0x", 2) < 0)
		return (-1);
	len = 2;
	if (x == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	else
	{
		result = print_pointer_address(x, base);
		if (result < 0)
			return (-1);
		len += result;
	}
	return (len);
}
