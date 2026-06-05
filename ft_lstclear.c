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
	t_list *caixa1;
	t_list *caixa2;

	if (!lst || !del)
		return ;
	if (lst == NULL)
		del(lst);
	caixa1 = *lst;
	caixa2 = caixa1->next;
	while (caixa1->next)
	{
		del(caixa1);
		free(caixa1);
		caixa1 = caixa2;
		caixa2 = caixa1->next;
	}
	del(caixa2);
	free(caixa1);
}
