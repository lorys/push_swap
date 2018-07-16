/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:32:23 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:53:12 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sorted(t_lst **a)
{
	t_lst *tmp;

	tmp = *a;
	if (t_lstlen(tmp) == 1)
		return (1);
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
			return (0);
		else if (tmp->next == NULL && tmp->content < tmp->prev->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
