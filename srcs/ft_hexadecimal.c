/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:49:34 by mvpee             #+#    #+#             */
/*   Updated: 2023/11/04 17:09:07 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_hexadecimal(unsigned int x, char *base)
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
		x /= 16;
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

int	ft_hexadecimal(unsigned int x, char a)
{
	char	base[17];
	int		len;
	int		result;

	if (a == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", sizeof(base));
	else
		ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (x == 0)
	{
		result = ft_putchar_fd_l('0', 1);
		if (result < 0)
			return (-1);
		return (result);
	}
	result = print_hexadecimal(x, base);
	if (result < 0)
		return (-1);
	len = result;
	return (len);
}
