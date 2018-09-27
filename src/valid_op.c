/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:28:25 by llopez            #+#    #+#             */
/*   Updated: 2018/09/27 12:55:37 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		valid_op(t_lst *a)
{
	t_lst *tma;
	t_lst *tmb;

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
