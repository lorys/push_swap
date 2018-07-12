/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:09:18 by llopez            #+#    #+#             */
/*   Updated: 2018/07/12 05:10:39 by llopez           ###   ########.fr       */
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
