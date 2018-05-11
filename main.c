/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/05/11 20:13:44 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list		**poutine(char **str, int size)
{
	a_list *nb_list;
	int		count;
	a_list **start;

	count = 0;
	nb_list = (a_list *)malloc(sizeof(a_list));
	nb_list->prev = NULL;
	start = &nb_list;
	while (count+1 <= size)
	{
		nb_list->content = ft_atoi(str[count]);
		if (count+2 <= size)
		{
			nb_list->null = 0;
			nb_list->next = (a_list *)malloc(sizeof(a_list));
			nb_list->next->prev = nb_list;
			nb_list = nb_list->next;
		}
		else
			nb_list->next = NULL;
		count++;
	}
	return (start);
}

void		print_list(a_list *list)
{
	a_list *here;

	here = list;
	if ((here->null == 1 && here->next == NULL) || here == NULL)
		return;
	list_top(here);
	while (here != NULL)
	{
		//printf("\naddr maillon current = %#x \nlist->content = %d\nlist->next = %#x\nlist->prev = %#x\nlist->null = %d\n\n", here, here->content, here->next, here->prev, here->null);
		ft_printf("%d\n", here->content);
		here = here->next;
	}
	printf("--------------");

}

a_list		*sort(a_list **list)
{
	a_list *b;
	a_list *a;
	a_list *last;

	a = *list;
	b = (a_list *)malloc(sizeof(a_list));
	b->null = 1;
	print_list(a);
/*	while (a != NULL)
	{*/
	printf("\n-------  SA\n");
		sx(list_top(a));
	print_list(a);
	printf("\n-------  SB\n");
		sx(list_top(b));
	print_list(b);
	printf("\n-------  SS\n");
		ss(list_top(a), list_top(b));
	printf("\n\n            A\n");
		print_list(list_top(a));
	printf("\n\n            B\n");
	print_list(list_top(b));
	printf("\n-------  PB\n");
	a = list_top(a);
	b = list_top(b);
		px(b, &a);
	printf("\n\n            A\n");
		print_list(a);
	printf("\n\n            B\n");
		print_list(b);

		
		last = a;
/*		a = a->next;
	}
	a = list_top(last);
	print_list(a);*/
	return (a);
}

int			main(int argc, char **argv)
{
	sort(poutine(&argv[1], argc-1));
	return (0);
}
