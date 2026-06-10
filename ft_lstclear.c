/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:47:43 by adrianda          #+#    #+#             */
/*   Updated: 2026/06/05 18:38:05 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_node;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
		{
			next_node = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = next_node;
		}
}
