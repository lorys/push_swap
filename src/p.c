/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:15:10 by llopez            #+#    #+#             */
/*   Updated: 2018/09/19 12:10:28 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	silent_hills(char *silent)
{
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}

void	px(t_lst **from, t_lst **to, char *silent)
{
	t_lst *tmp;

	if (*from == NULL)
		return ;
	tmp = (*from)->next;
	if (*to == NULL)
	{
		*to = *from;
		(*to)->next = NULL;
		(*to)->prev = NULL;
		(*from) = tmp;
		if (tmp)
			tmp->prev = NULL;
	}
	else
	{
		(*to)->prev = *from;
		(*to)->prev->next = (*to);
		(*to)->prev->prev = NULL;
		*to = (*to)->prev;
		*from = tmp;
		if (tmp)
			tmp->prev = NULL;
	}
	silent_hills(silent);
}
