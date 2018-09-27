/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:34:08 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:24:17 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_lst **x, char *silent)
{
	t_lst *last;

	if (*x == NULL || ((*x)->prev == NULL && (*x)->next == NULL))
		return ;
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

void	rr(t_lst **a, t_lst **b, char *silent)
{
	rx(a, "");
	rx(b, "");
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}

void	rx(t_lst **x, char *silent)
{
	t_lst *last;

	if (*x == NULL || ((*x)->next == NULL && (*x)->prev == NULL))
		return ;
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

void	rrr(t_lst **a, t_lst **b, char *silent)
{
	rrx(a, "");
	rrx(b, "");
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}
