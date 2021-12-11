/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:39:59 by mpezzull          #+#    #+#             */
/*   Updated: 2021/04/26 15:39:59 by mpezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (void *)malloc(sizeof(t_list));
	if (!(lst))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
