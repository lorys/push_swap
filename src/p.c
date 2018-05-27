/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:15:10 by llopez            #+#    #+#             */
/*   Updated: 2018/05/27 17:29:16 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(a_list **from, a_list **to, char *silent)
{
	a_list *tmp;

	if (*from == NULL)
		return;
	tmp = (*from)->next;
	if (*to == NULL)
	{
		*to = *from;
		(*to)->next = NULL;
		(*to)->prev = NULL;
		(*from) = tmp;
		if (*from != NULL)
			(*from)->prev = NULL;
	}
	else {
		(*to)->prev = *from;
		(*to)->prev->next = (*to);
		(*to)->prev->prev = NULL;
		*to = (*to)->prev;
		*from = tmp;
		if (*from != NULL)
			(*from)->prev = NULL;
	}
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}
