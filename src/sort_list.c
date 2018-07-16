/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:15:08 by llopez            #+#    #+#             */
/*   Updated: 2018/07/17 00:54:11 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list		*sort_list(a_list *a)
{
	a_list	*dup;
	a_list	*tmp;

	if (!(dup = (a_list *)malloc(sizeof(a_list))))
		exit(0);
	dup->prev = NULL;
	while (a != NULL)
	{
		dup->content = a->content;
		if (!(tmp = (a_list *)malloc(sizeof(a_list))))
			exit(0);
		dup->next = (a->next == NULL) ? NULL : tmp;
		if (a->next == NULL)
			free(tmp);
		if (a->next != NULL)
			dup->next->prev = dup;
		dup = (a->next != NULL) ? dup->next : dup;
		a = a->next;
	}
	dup->next = NULL;
	while (dup->prev != NULL)
		dup = dup->prev;
	sort_insert(&dup);
	return (dup);
}
