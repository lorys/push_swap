/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastoflist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:14:04 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:14:14 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*lastoflist(t_lst **x)
{
	t_lst *tmp;

	tmp = *x;
	if (*x == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
