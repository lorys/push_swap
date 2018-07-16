/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maillon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:14:31 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:20:56 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list		*get_maillon(a_list **lst, int i)
{
	a_list *a;

	a = *lst;
	while (a->next != NULL && i > 0)
	{
		a = a->next;
		i--;
	}
	return (a);
}
