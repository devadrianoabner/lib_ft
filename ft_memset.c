/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 00:44:46 by adrianda          #+#    #+#             */
/*   Updated: 2026/05/21 02:06:17 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t		i;

	ptr = (unsigned char *) s;
	i = 0;
	while (n > i)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
