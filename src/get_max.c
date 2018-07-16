/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:12:35 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:13:10 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list		*get_max(a_list **a)
{
	a_list	*at;
	a_list	*max;

	at = *a;
	max = NULL;
	while (at != NULL)
	{
		if (max == NULL)
			max = at;
		else if (max->content < at->content)
			max = at;
		at = at->next;
	}
	return (max);
}
