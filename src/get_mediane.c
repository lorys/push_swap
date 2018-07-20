/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:15:43 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 23:32:08 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_mediane(t_lst *a)
{
	t_lst	*sort_lst;
	int		tmp;

	sort_lst = sort_list(a);
	tmp = get_maillon(&sort_lst, t_lstlen(sort_lst) / 2)->content;
	free_list(sort_lst);
	return (tmp);
}