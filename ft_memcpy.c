/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 05:06:02 by adrianda          #+#    #+#             */
/*   Updated: 2026/05/21 05:21:43 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d_ptr = (unsigned char *) dest;
	s_ptr = (const unsigned char *) src;
	i = 0;
	while (n > i)
	{
		d_ptr[i] = s_ptr[i];
		i++;
	}
	return (dest);
}
