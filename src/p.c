/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:15:10 by llopez            #+#    #+#             */
/*   Updated: 2018/05/16 21:17:58 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(a_list **from, a_list **to)
{
	if (*from == NULL || *to == NULL || (*from)->null == 1 ||\
			(*to)->null == 1)
		return;
	(*to)->prev = (*from);
	(*to)->prev->next = (*to);
	(*from)->next = NULL;
	(*from)->prev = NULL;
	(*from)->null = 1;
}
