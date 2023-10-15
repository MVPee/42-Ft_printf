/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:10:47 by mvan-pee          #+#    #+#             */
/*   Updated: 2023/10/15 18:02:29 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_putchar_fd_l(char c, int fd);
int		ft_putstr_fd_l(char *s, int fd);
int		ft_putnbr_fd_l(int n, int fd);
int		ft_u_putnbr_fd_l(int n, int fd);
int		ft_hexadecimal(int x, char a);
int		ft_pointer(size_t x);
int		ft_int_len(int n);

#endif