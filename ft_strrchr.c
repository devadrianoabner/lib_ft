/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:48:54 by adrianda          #+#    #+#             */
/*   Updated: 2026/05/28 19:21:50 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	ptr_s = (char *) s;
	i = ft_strlen(ptr_s);
	if (c == 0)
		return (&ptr_s[i]);
	while (i >= 0)
	{
		if (ptr_s[i] == c)
			return (&ptr_s[i]);
		i--;
	}
	return (NULL);
}
