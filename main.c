/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/07/12 02:48:27 by llopez           ###   ########.fr       */
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
	usleep(80000);
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
	int		b;
	a_list	*tmp;

	tmp = NULL;
	i = 0;
	while (i < size)
	{
		b = 0;
				if (ft_isdigit(data[i][b]) && !ft_strchr(data[i], ' ') && \
				!ft_strchr(data[i], '\t'))
		{
			*a = (a_list *)malloc(sizeof(a_list));
			(*a)->prev = tmp;
			if (tmp != NULL)
				(*a)->prev->next = *a;
			(*a)->next = NULL;
			(*a)->content = ft_atoi(data[i]);
			tmp = *a;
			*a = (*a)->next;
		}
		else
		{
			while (data[i][b])
			{
				if (data[i][b] == '\t' || data[i][b] == ' ')
					b++;
				else if (ft_isdigit(data[i][b]))
				{
					(*a) = (a_list *)malloc(sizeof(a_list));
					(*a)->prev = tmp;
					if (tmp != NULL)
						(*a)->prev->next = *a;
					(*a)->next = NULL;
					(*a)->content = ft_atoi(&data[i][b]);
					tmp = *a;
					*a = (*a)->next;
					b += ft_intlen(ft_atoi(&data[i][b]));
				}
				else
					b++;
			}
		}
		i++;
	}
	*a = tmp;
	while ((*a)->prev != NULL)
		*a = (*a)->prev;
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

	at = *a;
	max = NULL;
	while (at != NULL)
	{
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
		else if (tmp->next == NULL && tmp->content < tmp->prev->content)
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
	dup->next = NULL;
	while (dup->prev != NULL)
		dup = dup->prev;
	sort_insert(&dup, &list_b, 1);
	return (dup);
}

int			get_mediane(a_list *a)
{
	a_list	*sort_lst;
	a_list	*tmp;

	sort_lst = sort_list(a);
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

void		quick_sort_rev(a_list **a, a_list **b)
{
	while (*b != get_max(b))
	{
		if (get_position_int(b, get_max(b)) < a_listlen(*b)/2)
			rx(b, "rb");
		else
			rrx(b, "rrb");
	}
	if ((*b)->content == get_max(b)->content)
		px(b, a, "pa");
	if (*b != NULL)
		quick_sort_rev(a, b);
}

void		quick_sort(a_list **a, a_list **b)
{
	int mediane;

	mediane = get_mediane(*a);
	while ((get_minus(a)->content < mediane))
	{
		if (sorted(a) && get_max(a)->content > get_max(b)->content && \
				lastoflist(a) == get_max(a) && \
				(*a)->content > get_max(b)->content)
			break;
		if ((*a)->content < mediane)
			px(a, b, "pb");
		else
			rrx(a, "rra");
	}
	if (!sorted(a) && a_listlen(*a) == 2)
		sx(a, "sa");
	if (a_listlen(*a) > 2 && !sorted(a))
		quick_sort(a, b);
	else
		quick_sort_rev(a, b);
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
			px(a, b, "");
		else
			if (po_min < a_listlen(*a)/2)
				rx(a, "");
			else
				rrx(a, "");
	}
	if (*a == NULL)
		while (*b != NULL)
			px(b, a, "");
	else
		sort_insert(a, b, silent);
}

void		prepare_sort(a_list **a, a_list **b)
{
	quick_sort(a, b);
}

int			main(int argc, char **argv)
{
	a_list *a;
	a_list *b;

	a = NULL;
	b = NULL;
	fill_list(&a, argv, argc);
	prepare_sort(&a, &b);
	return (0);
}
