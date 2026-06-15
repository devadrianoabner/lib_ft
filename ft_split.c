/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:16:38 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/14 22:34:20 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free_all(char **str, int j)
{
	while (j > 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**str;

	if (!s)	
		return (NULL);
	i = 0;
	j = 0;
	str = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i++] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			len = ft_get_word_len(&s[i], c);
			str[j] = calloc(1, len + 1);
			if (!str[j])
				return (ft_free_all(str, j));
			ft_strlcpy(str[j++], &s[i], len + 1);
		}
	}
	str[j] = NULL;
	return (str);
}
