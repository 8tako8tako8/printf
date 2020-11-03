/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:14:51 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/28 18:17:40 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current_elem;
	t_list *next_elem;

	current_elem = *lst;
	while (current_elem)
	{
		next_elem = current_elem->next;
		ft_lstdelone(current_elem, del);
		current_elem = next_elem;
	}
	*lst = NULL;
}
