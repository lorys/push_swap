/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:15:10 by llopez            #+#    #+#             */
/*   Updated: 2018/05/09 19:44:22 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(a_list *a, a_list *b)
{
	a_list *top_list;

	if (a != NULL && b != NULL && b->content != NULL)
	{
		while (b->prev != NULL)
			b = b->prev;
		top_list = b;
		b->next->prev = NULL;
		while (a->prev != NULL)
			a = a->prev;
		a->prev = b;
		a->prev->next = a;
	}
}

void		pb(a_list *a, a_list *b)
{
	if (a != NULL && b != NULL)
	{
		while (a->prev != NULL)
			a = a->prev;
		while (b->prev != NULL)
			b = b->prev;
		b->prev = (a_list *)malloc(sizeof(a_list));
		b->prev->content = a->content;
		a->next->prev = NULL;
	}
}
