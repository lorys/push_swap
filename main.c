/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/07/05 07:24:38 by llopez           ###   ########.fr       */
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

int		get_position_int(a_list **x, a_list *y)
{
	int		i;
	a_list	*tmp;

	tmp = *x;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp == y)
			return(i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
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

a_list		*between(a_list **a, int one, int two)
{
	a_list *tmp;

	if (*a == NULL)
		return (NULL);
	tmp = *a;
	while (tmp != NULL)
	{ 
		if ((tmp->content > one && tmp->content < two) || \
			(tmp->content < one && tmp->content > two))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			sorted(a_list **a)
{
	a_list *tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
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

a_list		*sort_list(a_list *a, int i)
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
		i--;
		if (i == 0)
			break;
	}
	dup->next = NULL;
	while (dup->prev != NULL)
		dup = dup->prev;
	sort_insert(&dup, &list_b, 1);
	return (dup);
}

int			get_mediane(a_list *a, int i)
{
	a_list	*sort_lst;
	a_list	*tmp;

	sort_lst = sort_list(a, i);
	tmp = get_maillon(&sort_lst, a_listlen(sort_lst) / 2);
	return (tmp->content);
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

a_list		*bigest_of_list(a_list *a)
{
	a_list *tmp;

	tmp = a;
	while (a->next != NULL)
	{
		if (a->content > tmp->content)
			tmp = a;
		a = a->next;
	}
	return (tmp);
}

int			sorted_part(a_list *a, int len)
{
	while (a->next != NULL && len)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
		len--;
	}
	return (1);
}

int			range_len(a_list *a, a_list **startend)
{
	int len;

	len = 0;
	while (a != NULL && a != startend[0])
		a = a->next;
	while (a != NULL && a != startend[1])
	{
		a = a->next;
		len++;
	}
	len = (len > 0) ? len + 1 : len;
	return (len);
}

a_list		*quick_pusha(a_list **a, a_list **b, int toscan)
{
		int		mediane;
		int		nbr_pushed;

		mediane = get_mediane(*b, toscan);
		while (get_max(b)->content > mediane && toscan)
		{
			if ((*b)->content > mediane)
			{
				px(b, a, "pa");
	print_multiple_list(*a, *b);
			}
			rrx(a, "rrb");
			toscan--;
		print_multiple_list(*a, *b);
		}
		return (mediane);
}

a_list		*quick_pushb(a_list **a, a_list **b, int toscan)
{
		int		mediane;
		int		nbr_pushed;

		mediane = get_mediane(*a, toscan);
		while (get_minus(a)->content < mediane && toscan)
		{
			if ((*a)->content < mediane)
			{
				px(a, b, "pb");
	print_multiple_list(*a, *b);
			}
			rrx(a, "rra");
	print_multiple_list(*a, *b);
			toscan--;
		}
		return (mediane);
}

void		quick_sort(a_list **a, a_list **b, a_list *medianes)
{
	if (medianes->next == NULL && medianes->prev == NULL)
		medianes->content = quick_pushb(a, b, a_listlen(*a));
	medianes->next = (a_list *)malloc(sizeof(a_list));
	medianes->next->next = NULL;
	medianes->prev = medianes;
	medianes->content = quick_pushb(a, b, a_listlen(*a));
	medianes = medianes->next;
	print_multiple_list(*a, *b);
	if (a_listlen(*a) > 2)
		quick_sort(a, b, medianes);
}

void		sort_insert(a_list **a, a_list **b, int silent)
{
	a_list	*min;
	int		po_min;
	
	if (*a != NULL)
	{
		min = get_minus(a);
		po_min = get_minus_int(a);
		if (*a == min)
			px(a, b, (silent != 1) ? "pb" : "");
		else
			if (po_min < a_listlen(*a)/2)
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

	i = 0;
	med = (a_list *)malloc(sizeof(a_list));
	med->prev = NULL;
	med->next = NULL;
	med->content = 0;
	quick_sort(a, b, &med);
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
	prepare_sort(&a, &b);
/*	if (sorted(&a))
		ft_printf("sorted with success !\n");
	else
		ft_printf("not sorted\n");
	print_multiple_list(a, b);*/
	return (0);
}
