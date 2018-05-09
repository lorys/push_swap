/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:04:58 by llopez            #+#    #+#             */
/*   Updated: 2018/05/09 17:38:41 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(a_list *a)
{
	int tmp;
	if (a->next != NULL && a != NULL)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
	}
}

void		sb(a_list *b)
{
	int tmp;
	if (b->next != NULL && b != NULL)
	{
		tmp = b->content;
		b->content = b->next->content;
		b->next->content = tmp;
	}
}

void		ss(a_list *a, a_list *b)
{
	sa(a);
	sb(b);
}
