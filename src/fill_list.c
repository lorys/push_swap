/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:30:40 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:30:59 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				else if ((ft_isdigit(data[i][b]) || data[i][b] == '-') && \
						valid_int(&data[i][b]))
				{
					(*a) = (a_list *)malloc(sizeof(a_list));
					(*a)->prev = tmp;
					if (tmp != NULL)
						(*a)->prev->next = *a;
					(*a)->next = NULL;
					(*a)->content = ft_atoi(&data[i][b]);
					tmp = *a;
					*a = (*a)->next;
					b += (data[i][b] == '-') ? 1 : 0 ;
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
