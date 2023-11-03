/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:35:25 by mvpee             #+#    #+#             */
/*   Updated: 2023/11/03 17:11:55 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	total_strings(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !(s[i] == c))
			i++;
	}
	return (count);
}

static int	sep_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	return (i);
}

static char	*ft_word(char const *s, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = sep_len(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_memory(char **strings, int i)
{
	while (i-- > 0)
		free(strings[i]);
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	strings = (char **)malloc(sizeof(char *) * (total_strings(s, c) + 1));
	if (!strings)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			strings[i] = ft_word(s, c);
			if (strings[i++] == NULL)
				return (free_memory(strings, i));
			s += sep_len(s, c);
		}
		if (*s)
			s++;
	}
	strings[i] = NULL;
	return (strings);
}
