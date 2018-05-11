/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:15:10 by llopez            #+#    #+#             */
/*   Updated: 2018/05/11 20:01:49 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		px(a_list *to, a_list **from)
{
	a_list *tmp;

	if ((*from)->null == 1)
		return;
	if (to->null == 1)
	{
		tmp = (*from)->next;
		to = *from;
		to->next = NULL;
		to->prev = NULL;
	}

}
