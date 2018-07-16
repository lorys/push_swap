/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:13:19 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:53:32 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_position_int(a_list **x, a_list *y)
{
	int		i;
	a_list	*tmp;

	tmp = *x;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp == y)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
