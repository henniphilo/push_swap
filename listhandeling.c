/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listhandeling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:48:37 by hwiemann          #+#    #+#             */
/*   Updated: 2023/10/06 16:48:37 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	pos = ft_lstlast(*lst);
	if (!pos)
		*lst = new;
	else
		pos->next = new;
}
