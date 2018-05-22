/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:04:58 by llopez            #+#    #+#             */
/*   Updated: 2018/05/22 15:51:52 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sx(a_list **x)
{
	int		tmp;
	if (*x == NULL || (*x)->next == NULL)
		return;
	tmp = (*x)->content;
	(*x)->content = (*x)->next->content;
	(*x)->next->content = tmp;
}

void		ss(a_list **a, a_list **b)
{
	sx(a);
	sx(b);
}
