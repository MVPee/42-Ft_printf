/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_fd_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:40:50 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/11/03 19:28:42 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_u_int_len(unsigned int a)
{
	int	len;

	len = 1;
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
