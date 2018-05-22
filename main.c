/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/05/22 17:08:28 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_list(a_list *a)
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
	px(b, a);
	px(a, b);
	rx(a);
	rx(b);
	rr(a, b);
	rrx(a);
	rrr(a, b);
}

void		oi(a_list **a, a_list **b)
{
	char str[4];

	str[2] = '\0';
	str[3] = '\0';
	read(1, &str, 3);
	if (str[0] == '\n')
		oi(a, b);
	if (!ft_strncmp(str, "sa", 2))
		sx(a);
	else if (!ft_strncmp(str, "rra", 3))
		rrx(a);
	else if (!ft_strncmp(str, "rrb", 3))
		rrx(b);
	else if (!ft_strncmp(str, "sb", 2))
		sx(b);
	else if (!ft_strncmp(str, "pb", 2))
		px(a, b);
	else if (!ft_strncmp(str, "pa", 2))
		px(b, a);
	else if (!ft_strncmp(str, "ra", 2))
		rx(a);
	else if (!ft_strncmp(str, "rb", 2))
		rx(b);
	else if (!ft_strncmp(str, "rr", 2))
		rr(a, b);
// a retirer

	system("clear");
		
	printf("==LIST A===(%s)\n", str);
	print_list(*a);
	printf("\n==LIST B====(%s)\n", str);
	print_list(*b);
	oi(a, b);
}

int			main(int argc, char **argv)
{
	a_list *a;
	a_list *b;

	a = (a_list *)malloc(sizeof(a_list));
	b = NULL;
	if (!ft_strcmp(argv[1], "-I"))
		fill_list(&a, &argv[2], argc-2);
	else
		fill_list(&a, &argv[1], argc-1);
	if (!ft_strcmp(argv[1], "-I"))
		oi(&a, &b);
	else
		sort(&a, &b);
	print_list(a);
	printf("\nlist b\n");
	print_list(b);
	/*while (a != NULL)
	{
		printf("\n==========\nprev = %p\nnext = %p\ncontent = %d\n=========\n", a->prev, a->next, a->content);
		a = a->next;
	}*/
	return (0);
}
