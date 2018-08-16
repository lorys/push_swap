/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:15:43 by llopez            #+#    #+#             */
/*   Updated: 2018/08/16 15:08:39 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_mediane(t_lst *a, t_lst *b)
{
	t_lst	*sort_lst;
	int		tmp;

	sort_lst = sort_list(a);
	if ((t_lstlen(a) + t_lstlen(b)) > 300 && t_lstlen(a) > 7)
		tmp = get_maillon(&sort_lst, t_lstlen(sort_lst) / 7)->content;
	else if ((t_lstlen(a) + t_lstlen(b)) <= 100 \
			&& t_lstlen(a) > 3)
		tmp = get_maillon(&sort_lst, t_lstlen(sort_lst) / 3)->content;
	else
		tmp = get_maillon(&sort_lst, t_lstlen(sort_lst) / 2)->content;
	free_list(sort_lst);
	return (tmp);
}
