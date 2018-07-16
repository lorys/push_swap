/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_multiple_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:29:25 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:29:39 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_multiple_list(t_lst *a, t_lst *b)
{
	system("clear");
	printf("%10s%20s\n", "LIST A", "LIST B");
	if (a == NULL)
		printf("(null)");
	if (b == NULL)
		printf("%20s\n", "(null)");
	while (b != NULL || a != NULL)
	{
		if (a != NULL)
			printf("%10d", a->content);
		else
			printf("%10s", "");
		if (b != NULL)
			printf("%20d", b->content);
		else
			printf("%10s", "");
		printf("\n");
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
}
