/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:06:01 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/27 21:11:42 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*head;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = lst;
	newlist = NULL;
	while (head != NULL)
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		tmp -> content = f(head ->content);
		tmp -> next = NULL;
		ft_lstadd_back(&newlist, tmp);
		head = head->next;
	}
	return (newlist);
}
