/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:21:39 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/15 16:43:57 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	buff;

	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		buff = ft_strlen(s) - start + 1;
	else
		buff = len + 1;
	dest = ft_calloc(buff, 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, buff);
	return (dest);
}
