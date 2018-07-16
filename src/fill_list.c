/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:30:40 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 22:01:48 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_list_partone(char *data, int *b, a_list **a, \
		a_list **tmp)
{
	while (data[*b])
	{
		if (data[*b] == '\t' || data[*b] == ' ')
			(*b)++;
		else if ((ft_isdigit(data[*b]) || data[*b] == '-') && \
				valid_int(&(data[*b])))
		{
			if (!(*a = (a_list *)malloc(sizeof(a_list))))
				exit(0);
			(*a)->prev = *tmp;
			if (*tmp != NULL)
				(*a)->prev->next = *a;
			(*a)->next = NULL;
			(*a)->content = ft_atoi(&data[*b]);
			*tmp = *a;
			*a = (*a)->next;
			(*b) += (data[*b] == '-') ? 1 : 0;
			(*b) += ft_intlen(ft_atoi(&data[*b]));
		}
		else
			(*b)++;
	}
}

void		fill_list_parttwo(a_list **a, int *i, char **data, a_list **tmp)
{
	if (!(*a = (a_list *)malloc(sizeof(a_list))))
		exit(0);
	(*a)->prev = *tmp;
	if (*tmp != NULL)
		(*a)->prev->next = *a;
	(*a)->next = NULL;
	(*a)->content = ft_atoi(data[*i]);
	*tmp = *a;
	*a = (*a)->next;
}

void		fill_list(a_list **a, char **data, int size, int checker)
{
	int		i;
	int		b;
	a_list	*tmp;

	tmp = NULL;
	i = 1;
	if (!ft_strcmp(data[i], "-v") && checker)
		i++;
	while (i < size)
	{
		b = 0;
		if ((ft_isdigit(data[i][b]) || data[i][b] == '-') && \
				!ft_strchr(data[i], ' ') && !ft_strchr(data[i], '\t') \
				&& valid_int(&data[i][b]))
			fill_list_parttwo(a, &i, data, &tmp);
		else
			fill_list_partone(data[i], &b, a, &tmp);
		i++;
	}
	*a = tmp;
	while ((*a)->prev != NULL)
		*a = (*a)->prev;
}
