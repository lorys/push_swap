/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:34:08 by llopez            #+#    #+#             */
/*   Updated: 2018/05/10 17:27:14 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(a_list *a)
{
	a_list *top_value;

	while (a->prev != NULL)
		a = a->prev;
	top_value = a;
	a->next->prev = NULL;
	while (a->next != NULL)
		a = a->next;
	a->next = top_value;
	a->next->prev = a;
	a->next->next = NULL;
}

void		rb(a_list *b)
{
	a_list *top_value;

	while (b->prev != NULL)
		b = b->prev;
	top_value = b;
	b->next->prev = NULL;
	while (b->next != NULL)
		b = b->next;
	b->next = b;
	b->next->prev = b;
	b->next->next = NULL;
}

void		rr(a_list *a, a_list *b)
{
	ra(a);
	rb(b);
}

void		rra(a_list *a)
{
	a_list *bottom_value;

	while (a->next != NULL)
		a = a->next;
	bottom_value = a;
	a->prev->next = NULL;
	while (a->prev != NULL)
		a = a->prev;
	a->prev = bottom_value;
	a->prev->next = a;
	a->prev->prev = NULL;
}

void		rrb(a_list *b)
{
	a_list *bottom_value;

	while (b->next != NULL)
		b = b->next;
	bottom_value = b;
	b->prev->next = NULL;
	while (b->prev != NULL)
		b = b->prev;
	b->prev = bottom_value;
	b->prev->next = b;
	b->prev->prev = NULL;
}

void		rrr(a_list *a, a_list *b)
{
	rra(a);
	rrb(b);
}
