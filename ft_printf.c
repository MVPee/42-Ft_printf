/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@19.be>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:12:15 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/10/16 10:26:50 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_is_for_printf(char a)
{
	if (a == 'c' || a == 's' || a == 'p' || a == 'd' || a == 'i' || a == 'i'
		|| a == 'u' || a == 'x' || a == 'X' || a == '%')
		return (1);
	return (0);
}

void	ft_checkflag(va_list args, char a, int *len)
{
	int unsigned_num;

	if (a == 'c')
		*len += ft_putchar_fd_l(va_arg(args, int), 1);
	else if (a == 's')
		*len += ft_putstr_fd_l(va_arg(args, char *), 1);
	else if (a == 'p')
		*len += ft_pointer(va_arg(args, size_t));
	else if (a == 'd' || a == 'i')
		*len += ft_putnbr_fd_l(va_arg(args, int), 1);
	else if (a == 'u')
	{
		unsigned_num = va_arg(args, int);
		if(unsigned_num < 0)
			unsigned_num *= -1;
		*len += ft_putnbr_fd_l(unsigned_num, 1);
	}
	else if (a == 'x' || a == 'X')
		*len += ft_hexadecimal(va_arg(args, int), a);
	else if (a == '%')
		*len += ft_putchar_fd_l('%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_is_for_printf(format[i + 1]))
		{
			ft_checkflag(args, format[i + 1], &len);
			i++;
		}
		else
		{
			ft_putchar_fd_l(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
