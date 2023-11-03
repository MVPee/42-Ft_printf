/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:14:13 by mvpee             #+#    #+#             */
/*   Updated: 2023/10/15 18:05:10 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pointer(size_t x)
{
	char	base[17];
	char	string[25];
	int		i;
	int		len;

	i = 0;
	ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	ft_putstr_fd_l("0x", 1);
	len = 2;
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
	{
		len += ft_putchar_fd_l(string[i], 1);
	}
	return (len);
}
