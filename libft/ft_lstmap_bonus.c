/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:52:54 by mlarioui          #+#    #+#             */
/*   Updated: 2024/09/26 18:11:04 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first_itm;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	first_itm = ft_lstnew(f(lst->content));
	if (!first_itm)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&first_itm, del);
			return (NULL);
		}
		ft_lstadd_back(&first_itm, tmp);
		lst = lst->next;
	}
	return (first_itm);
}
