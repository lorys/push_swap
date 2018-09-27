/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:30:40 by llopez            #+#    #+#             */
/*   Updated: 2018/09/27 17:20:26 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_int(t_lst **a, char *data)
{
	if (!valid_int(data))
	{
		(*a)->next = NULL;
		while ((*a)->prev != NULL)
			(*a) = (*a)->prev;
		return (0);
	}
	return (1);
}

void	fill_maillon(t_lst **a, int data, t_lst **tmp)
{
	(*a)->next = NULL;
	(*a)->content = data;
	*tmp = *a;
	*a = (*a)->next;
}

int		fill_list_partone(char *data, t_lst **a, t_lst **tmp)
{
	int i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '\t' || data[i] == ' ')
			i++;
		else if (ft_isdigit(data[i]) || data[i] == '-')
		{
			if (!check_int(a, &data[i]) || \
				!(*a = (t_lst *)malloc(sizeof(t_lst))))
				return (0);
			(*a)->prev = *tmp;
			if (*tmp != NULL)
				(*a)->prev->next = *a;
			fill_maillon(a, ft_atoi(&data[i]), tmp);
			while (data[i] == '-' || ft_isdigit(data[i]))
				i++;
		}
		else
			while (ft_isdigit(data[i]))
				i++;
	}
	return (1);
}

int		fill_list_parttwo(t_lst **a, int *i, char **data, t_lst **tmp)
{
	if (valid_int(data[*i]))
		return (0);
	if (!(*a = (t_lst *)malloc(sizeof(t_lst))))
		exit(0);
	(*a)->prev = *tmp;
	if (*tmp != NULL)
		(*a)->prev->next = *a;
	(*a)->next = NULL;
	(*a)->content = ft_atoi(data[*i]);
	*tmp = *a;
	*a = (*a)->next;
	return (1);
}

int		fill_list(t_lst **a, char **data, int size, int checker)
{
	int		i;
	int		b;
	t_lst	*tmp;

	tmp = NULL;
	i = (!ft_strcmp(data[1], "-v") && checker) ? 2 : 1;
	while (i < size)
	{
		b = 0;
		if (!(((ft_isdigit(data[i][b]) || data[i][b] == '-') && \
				!ft_strchr(data[i], ' ') && !ft_strchr(data[i], '\t') && \
				fill_list_parttwo(a, &i, data, &tmp)) || \
				(fill_list_partone(data[i], a, &tmp))))
			return (0);
		i++;
	}
	*a = tmp;
	while ((*a)->prev != NULL)
		*a = (*a)->prev;
	return (1);
}
