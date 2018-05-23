/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/05/23 01:16:43 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_list(a_list *a)
{
	if (a == NULL)
		printf("(null)\n");
	while (a != NULL)
	{
		//ft_printf("addr %p\n", a);
		ft_printf("%d\n", a->content);
		//ft_printf("next = %p\n", a->next);
		//ft_printf("prev = %p\n", a->prev);
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

int		get_minus_int(a_list **a)
{
	a_list	*at;
	a_list	*minus;
	int		length;
	int		minus_po;

	length = 0;
	at = *a;
	minus = NULL;
	while (at != NULL)
	{
		length++;
		if (minus == NULL)
			minus = at;
		else if (minus->content > at->content)
		{
			minus = at;
			minus_po = length;
		}
		at = at->next;
	}
	return (minus_po);
}

int			a_listlen(a_list *a)
{
	int	length;

	length = 0;
	while (a != NULL)
	{
		a = a->next;
		length++;
	}
	return (length);
}

void		sort(a_list **a, a_list **b)
{
	a_list	*at;
	a_list	*minus;
	int		po_minus;
	int		length;

	length = a_listlen(*a);
	po_minus = get_minus_int(a);
	at = *a;
	minus = get_minus(a);
	if (*a == minus)
	{
		px(a, b);
		ft_printf("pb\n");
	}
	else if (po_minus <= (length/2))
	{
		rrx(a);
		ft_printf("rra\n");
	}
	else if (po_minus > (length/2))
	{
		rx(a);
		ft_printf("ra\n");
	}
	usleep(1000000);
	system("clear");
	printf("==LIST A===\n");
	print_list(*a);
	printf("\n==LIST B====)\n");
	print_list(*b);
	if (*a != NULL) { sort(a, b); }
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
	/*print_list(a);
	printf("\nlist b\n");
	print_list(b);
	while (a != NULL)
	{
		printf("\n==========\nprev = %p\nnext = %p\ncontent = %d\n=========\n", a->prev, a->next, a->content);
		a = a->next;
	}*/
	return (0);
}
