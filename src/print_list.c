/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:29:51 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:30:08 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_list(t_lst *a)
{
	if (a == NULL)
		printf("(null)\n");
	while (a != NULL)
	{
		ft_printf("addr %p\n", a);
		ft_printf("%d\n", a->content);
		ft_printf("next = %p\n", a->next);
		ft_printf("prev = %p\n", a->prev);
		a = a->next;
	}
}
