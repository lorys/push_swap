/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/05/10 21:57:26 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list		*poutine(char **str, int size)
{
	a_list *nb_list;
	int		count;
	a_list *start;

	count = 0;
	nb_list = (a_list *)malloc(sizeof(a_list));
	nb_list->prev = NULL;
	start = nb_list;
	while (count+1 <= size)
	{
		nb_list->content = ft_atoi(str[count]);
		if (count+2 <= size)
		{
			nb_list->next = malloc(sizeof(a_list));
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
	if (here == NULL)
		return;
	while (here->prev != NULL)
		here = here->prev;
	while (here != NULL)
	{
		printf("\naddr maillon current = %#x \n list->content = %d\nlist->next = %#x\nlist->prev = %#x\n\n", here, here->content, here->next, here->prev);
		//ft_printf("%d\n", here->content);
		here = here->next;
	}
	printf("--------------");

}

a_list		*sort(a_list *list)
{
	a_list *b;
	a_list *a;

	a = list;
	b = NULL;
	while (a->next != NULL)
	{
		printf("----sa\n");
		sa(a);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----sb\n");
		sb(b);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----ss\n");
		ss(a, b);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----pa\n");
		pa(a, b);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----pb\n");
		pb(a, b);
		print_list(a);
		ft_printf("\n++\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----ra\n");
		ra(a);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----rb\n");
		rb(b);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----rr\n");
		rr(a, b);
		print_list(a);
		ft_printf("\n++\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----rra\n");
		rra(a);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----rrb\n");
		rrb(b);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
		printf("----rrr\n");
		rrr(a, b);
		print_list(a);
		ft_printf("\n");
		print_list(b);
		ft_printf("\n--------------\n");
	}
	while (a->prev != NULL)
		a = a->prev;
	return (a);
}

int			main(int argc, char **argv)
{
	print_list(sort(poutine(&argv[1], argc-1)));
	return (0);
}
