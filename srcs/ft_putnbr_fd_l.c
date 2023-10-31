/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:02:13 by mvpee             #+#    #+#             */
/*   Updated: 2023/10/13 18:02:13 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_int_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr_fd_l(int n, int fd)
{
	int	len;

	if (n == -2147483648)
	{
		ft_putstr_fd_l("-2147483648", fd);
		return (11);
	}
	len = ft_int_len(n);
	if (n < 0)
	{
		ft_putchar_fd_l('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd_l(n / 10, fd);
	ft_putchar_fd_l(n % 10 + '0', fd);
	return (len);
}
