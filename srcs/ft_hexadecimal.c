/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:49:34 by mvpee             #+#    #+#             */
/*   Updated: 2023/11/03 19:24:00 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexadecimal(unsigned int x, char a)
{
	char	base[17];
	char	string[25];
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (a == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", sizeof(base));
	else
		ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (x == 0)
	{
		len += ft_putchar_fd_l('0', 1);
		return (len);
	}
	while (x != 0)
	{
		string[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		len += ft_putchar_fd_l(string[i], 1);
	return (len);
}
