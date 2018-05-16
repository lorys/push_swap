/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/05/16 21:15:45 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_list(a_list *a)
{
	while (a != NULL)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}

void		fill_list(a_list **a, char **data, int size)
{
	int		i;
	a_list **tmp;

	i = 0;
	tmp = a;
	while (i < size)
	{
		(*a)->content = ft_atoi(data[i]);
		if (i+1 < size)
			(*a)->next = (a_list *)malloc(sizeof(a_list));
		else
			(*a)->next = NULL;
		if (i == 0)
			(*a)->prev = NULL;
		if (i+1 < size)
			(*a)->next->prev = (*a);
		if ((*a)->next != NULL)
			(*a) = (*a)->next;
		i++;
	}
	while ((*a)->prev != NULL)
	{
		(*a) = (*a)->prev;
	}
}

void		sort(a_list **a, a_list **b)
{
	sx(a);
	sx(b);
	ss(a, b);
	/*px(b, a);*/
	px(a, b);/*
	rx(a);
	rx(b);
	rr(a, b);
	rrx(a);
	rrr(a, b);*/
}

int			main(int argc, char **argv)
{
	a_list *a;
	a_list *b;

	a = (a_list *)malloc(sizeof(a_list));
	b = (a_list *)malloc(sizeof(a_list));
	b->null = 1;
	fill_list(&a, &argv[1], argc-1);
	sort(&a, &b);
	print_list(a);
	/*while (a != NULL)
	{
		printf("\n==========\nprev = %p\nnext = %p\ncontent = %d\n=========\n", a->prev, a->next, a->content);
		a = a->next;
	}*/

	return (0);
}
