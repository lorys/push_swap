/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:15:10 by llopez            #+#    #+#             */
/*   Updated: 2018/05/10 22:00:55 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(a_list *a, a_list *b)
{
	a_list *top_list;

	list_top(b);
	list_top(a);
	if (a != NULL && b != NULL)
	{
		b->prev = a;
		a->next->prev = NULL;
	}
}

void		pb(a_list *a, a_list *b)
{
	a_list *tmp;
	if (a != NULL)
	{
		while (a->prev != NULL)
			a = a->prev;
		if (b == NULL)
		{
			b->content = a->content;
			a->next->prev = NULL;
			tmp = a->next;
			free(a);
			a = tmp;
		}
		else
		{
			while (b->prev != NULL)
				b = b->prev;
			b->prev = (a_list *)malloc(sizeof(a_list));
			b->prev->content = a->content;
			a->next->prev = NULL;
			tmp = a->next;
			free(a);
			a = tmp;
		}
	}
}
