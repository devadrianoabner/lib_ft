/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:23:15 by adrianda          #+#    #+#             */
/*   Updated: 2026/05/29 22:46:18 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] != 0 && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	j;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strnlen(dst, size);
	i = 0;
	j = dst_len;
	if (j >= size)
		return (src_len + size);
	while (j < size - 1 && src[i] != 0)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (src_len + dst_len);
}
