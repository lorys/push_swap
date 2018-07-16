/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:28:25 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:28:41 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		valid_op(a_list *a)
{
	a_list *tma;
	a_list *tmb;

	tma = a;
	while (tma != NULL)
	{
		tmb = a;
		while (tmb != NULL)
		{
			if (tmb->content == tma->content && tmb != tma)
				return (0);
			tmb = tmb->next;
		}
		tma = tma->next;
	}
	return (1);
}
