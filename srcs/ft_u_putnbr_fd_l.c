/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_fd_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:40:50 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/10/31 17:22:18 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_u_int_len(unsigned int a)
{
	int	len;

	len = 1;
	if (a < 0)
	{
		len++;
		a *= -1;
	}
	while (a > 9)
	{
		len++;
		a /= 10;
	}
	return (len);
}

int	ft_u_putnbr_fd_l(int n, int fd)
{
	int				len;
	unsigned int	a;

	if (n < 0)
		a = (UINT_MAX + n) + 1;
	else
		a = n;
	len = ft_u_int_len(a);
	if (a >= 10)
		ft_putnbr_fd_l(a / 10, fd);
	ft_putchar_fd_l(a % 10 + '0', fd);
	return (len);
}
