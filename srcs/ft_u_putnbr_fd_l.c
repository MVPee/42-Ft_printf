/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_fd_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:40:50 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/01 09:18:42 by mvan-pee         ###   ########.fr       */
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

int	ft_u_putnbr_fd_l(unsigned int n, int fd)
{
	int				len;

	len = ft_u_int_len(n);
	if (n >= 10)
		ft_putnbr_fd_l(n / 10, fd);
	ft_putchar_fd_l(n % 10 + '0', fd);
	return (len);
}
