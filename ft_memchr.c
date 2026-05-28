/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:02:25 by adrianda          #+#    #+#             */
/*   Updated: 2026/05/28 02:26:52 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;
	unsigned char		param;

	ptr = (const unsigned char *) str;
	param = (unsigned char) c;
	i = 0;
	while (n > i)
	{
		if (ptr[i] == c)
			return ((void *) &ptr[i]);
		i++;
	}
	return (NULL);
}
