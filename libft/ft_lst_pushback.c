/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:31:47 by jterrell          #+#    #+#             */
/*   Updated: 2019/10/18 17:36:15 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_pushback(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!alst || !new)
		return ;
	current = *alst;
	if (!current)
		*alst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
