/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:46:48 by jlaisne           #+#    #+#             */
/*   Updated: 2022/11/21 10:02:27 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;
	char	*str;

	res = NULL;
	if (!del || !f)
		return (NULL);
	while (lst)
	{
		str = (*f)(lst->content);
		node = ft_lstnew(str);
		if (!node)
		{
			(del)(str);
			ft_lstclear(&res, (*del));
			return (NULL);
		}
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
