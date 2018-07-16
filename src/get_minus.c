/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:11:55 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:41:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list		*get_minus(a_list **a)
{
	a_list	*at;
	a_list	*minus;
	int		length;

	length = 0;
	at = *a;
	minus = NULL;
	while (at != NULL)
	{
		length++;
		if (minus == NULL)
			minus = at;
		else if (minus->content > at->content)
			minus = at;
		at = at->next;
	}
	return (minus);
}
