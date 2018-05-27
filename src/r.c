/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:34:08 by llopez            #+#    #+#             */
/*   Updated: 2018/05/27 17:37:54 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(a_list **x, char *silent)
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
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}

void	rr(a_list **a, a_list **b, char *silent)
{
	rx(a, (silent[0] != '\0') ? silent : "");
	rx(b, (silent[0] != '\0') ? silent : "");
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}

void	rrx(a_list **x, char *silent)
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
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}

void	rrr(a_list **a, a_list **b, char *silent)
{
	rrx(a, (silent[0] != '\0') ? silent : "");
	rrx(b, (silent[0] != '\0') ? silent : "");
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}
