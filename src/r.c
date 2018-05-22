/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:34:08 by llopez            #+#    #+#             */
/*   Updated: 2018/05/22 17:05:34 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(a_list **x)
{
	a_list *last;

	if (*x == NULL || ((*x)->prev == NULL && (*x)->next == NULL))
		return;
	last = *x;
	while (last->next != NULL)
		last = last->next;
	(*x)->prev = last;
	last->prev->next = NULL;
	(*x)->prev->prev = NULL;
	(*x)->prev->next = *x;
	*x = (*x)->prev;
}

void	rr(a_list **a, a_list **b)
{
	rx(a);
	rx(b);
}

void	rrx(a_list **x)
{
	a_list *last;

	if (*x == NULL || ((*x)->next == NULL && (*x)->prev == NULL))
		return;
	last = *x;
	while (last->next != NULL)
		last = last->next;
	last->next = *x;
	*x = (*x)->next;
	last->next->prev = last;
	last->next->next = NULL;
}

void	rrr(a_list **a, a_list **b)
{
	rrx(a);
	rrx(b);
}
