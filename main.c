/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/05/28 21:18:06 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_multiple_list(a_list *a, a_list *b)
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

void		print_list(a_list *a)
{
	system("clear");
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
	a_list	**tmp;

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
		(*a) = (*a)->prev;
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

a_list		*get_max(a_list **a)
{
	a_list	*at;
	a_list	*max;
	int		length;

	length = 0;
	at = *a;
	max = NULL;
	while (at != NULL)
	{
		length++;
		if (max == NULL)
			max = at;
		else if (max->content < at->content)
			max = at;
		at = at->next;
	}
	return (max);
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

int		get_max_int(a_list **a)
{
	a_list	*at;
	a_list	*max;
	int		length;
	int		max_po;

	length = 0;
	at = *a;
	max = NULL;
	while (at != NULL)
	{
		length++;
		if (max == NULL)
			max = at;
		else if (max->content < at->content)
		{
			max = at;
			max_po = length;
		}
		at = at->next;
	}
	return (max_po);
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

a_list		*lastoflist(a_list **x)
{
	a_list *tmp;

	tmp = *x;
	if (*x == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

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

int			sorted(a_list **a)
{
	a_list *tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
			return (0);
		else if (tmp->prev != NULL && tmp->content < tmp->prev->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			bigest(a_list *x, a_list *pivot)
{
	while (x != NULL)
	{
		if (x->content > pivot->content)
			return (1);
		x = x->next;
	}
	return (0);
}

a_list		*sort_list(a_list *a)
{
	a_list	*dup;
	a_list	*prev;
	a_list	*list_b;

	dup = (a_list *)malloc(sizeof(a_list));
	dup->prev = NULL;
	list_b = NULL;
	while (a != NULL)
	{
		dup->content = a->content;
		dup->next = (a->next == NULL) ? NULL : (a_list *)malloc(sizeof(a_list));
		if (a->next != NULL)
			dup->next->prev = dup;
		if (a->next != NULL)
			dup = dup->next;
		a = a->next;
	}
	while (dup->prev != NULL)
		dup = dup->prev;
sort_insert(&dup, &list_b, 1);
	return (dup);
}

a_list		*get_mediane(a_list *a)
{
	a_list	*sort_lst;

	sort_lst = sort_list(a);
	return (get_maillon(&sort_lst, a_listlen(sort_lst) / 2));
}

int			lower_than(a_list *a, a_list *pivot)
{
	while (a != NULL)
	{
		if (a->content < pivot->content)
			return (1);
		a = a->next;
	}
	return (0);
}

void		quick_sort(a_list **a, a_list **b, a_list *med)
{
	a_list	*mediane; 
	int		i;

	mediane = get_mediane(*a);
	printf("mediane = %d\n", mediane->content);
	if (med->next == NULL)
	{
		med->content = mediane->content;
		printf("save mediane...\n");
		med->next = (a_list *)malloc(sizeof(a_list));
		med->next->prev = med;
	}
		printf("\033[41m cherche tout ce qui est en dessous de la mediane..\n");
	while (lower_than(*a, med))
	{
		printf("%d < %d ?\n", (*a)->content, med->content);
		if ((*a)->content <= med->content)
		{
		printf("\033[0m \033[44m On push %d sur B \033[0m \n", (*a)->content);
			px(a, b, "pb");
		}
		else
		{
			printf("suivant..\n");
			rrx(a, "rra");
		}
	}
	printf("\033[0m on a push tout ce qui etait au dessous de la mediane %d\n", mediane->content);
	printf("\n la list A fait %d\n", a_listlen(*a));
	if (a_listlen(*a) > 2)
	{
		printf("On recommence !\n");
		med = med->next;
		quick_sort(a, b, med);
	}
	else {
		if ((*a)->content > (*a)->next->content)
			sx(a, "sa");
		printf("on remet sur A les elements plus grand que la mediane %d\n", med->content);
	printf("list a\n");
	print_list(*a);
	printf("list b\n");
	print_list(*b);
	i = a_listlen(*b);
		while (i < a_listlen(*b))
		{
			printf("%d > %d ?\n", (*b)->content, med->prev->content);
			if ((*b)->content > med->prev->content)
			{
				printf("On push %d sur A\n", (*b)->content);
				px(b, a, "pa");
	print_list(*a);
			}
			else
			{
				printf("suivant..\n");
				rrx(b, "rra");
			}
			i--;
		}
		printf("On a push tout ce qui etait au dessus de la mediane %d\n", med->prev->content);
	usleep(90000);
		printf("et sa repart !\n");
	usleep(90000);
		med = med->next;
		quick_sort(a, b, med);
	}
}

void		sort_insert(a_list **a, a_list **b, int silent)
{
	a_list	*max;
	int		po_max;

	max = get_max(a);
	po_max = get_max_int(a);
	if (*a == max)
		px(a, b, (silent != 1) ? "pb" : "");
	else {
		if (po_max < a_listlen(*a)/2)
			rrx(a, (silent != 1) ? "rra" : "");
		else
			rx(a, (silent != 1) ? "ra" : "");
	}
	if (*a == NULL)
		while (*b != NULL)
			px(b, a, (silent != 1) ? "pa" : "");
	else
		sort_insert(a, b, silent);
}

void		prepare_sort(a_list **a, a_list **b)
{
	a_list	*med;
	int		i;

	printf("----------------------------------------------------\n");
	i = 0;
	med = (a_list *)malloc(sizeof(a_list));
	med->prev = NULL;
	med->content = 0;
	med->next = (a_list *)malloc(sizeof(a_list));
	med->next->prev = med;
	med = med->next;
		quick_sort(a, b, med);
		while (get_minus(a) != *a)
			rrx(a, "rra");
		printf("taille list a = %d\n", a_listlen(*a));
		print_list(*a);
		while (i < a_listlen(*a))
		{
			printf("mediane saved = %d\n", med[i].content);
			i++;
		}
}

void		oi(a_list **a, a_list **b)
{
	char str[4];

	str[3] = '\0';
	read(1, &str, 3);
	if (str[0] == '\n')
		oi(a, b);
	if (!ft_strncmp(str, "sa", 2))
		sx(a, "");
	else if (!ft_strncmp(str, "rra", 3))
		rrx(a, "");
	else if (!ft_strncmp(str, "rrb", 3))
		rrx(b, "");
	else if (!ft_strncmp(str, "sb", 2))
		sx(b, "");
	else if (!ft_strncmp(str, "pb", 2))
		px(a, b, "");
	else if (!ft_strncmp(str, "pa", 2))
		px(b, a, "");
	else if (!ft_strncmp(str, "ra", 2))
		rx(a, "");
	else if (!ft_strncmp(str, "rb", 2))
		rx(b, "");
	else if (!ft_strncmp(str, "rr", 2))
		rr(a, b, "");
	print_multiple_list(*a, *b);
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
		prepare_sort(&a, &b);
	//print_multiple_list(a, b);
	if (sorted(&a))
		ft_printf("sorted with success !\n");
	else
		ft_printf("not sorted\n");
	return (0);
}
