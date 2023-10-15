/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:32:00 by mvpee             #+#    #+#             */
/*   Updated: 2023/10/15 17:02:20 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		len;

	i = -1;
	len = ft_strlen(src);
	if (!size)
		return (len);
	while (++i < size - 1 && src[i])
		dst[i] = src[i];
	if (size > i)
		dst[i] = 0;
	return (len);
}
