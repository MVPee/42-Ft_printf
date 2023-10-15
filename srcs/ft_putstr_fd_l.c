/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:06:20 by mvpee             #+#    #+#             */
/*   Updated: 2023/10/13 18:06:20 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_fd_l(char *s, int fd)
{
	int	i;
	int	len;

	len = 0;
	if (!s)
		return (len);
	i = -1;
	while (s[++i])
		len += ft_putchar_fd_l(s[i], fd);
	return (len);
}
