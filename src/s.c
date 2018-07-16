/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:04:58 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:22:10 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sx(t_lst **x, char *silent)
{
	int		tmp;

	if (*x == NULL || (*x)->next == NULL)
		return ;
	tmp = (*x)->content;
	(*x)->content = (*x)->next->content;
	(*x)->next->content = tmp;
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}

void		ss(t_lst **a, t_lst **b, char *silent)
{
	sx(a, (silent[0] != '\0') ? silent : "");
	sx(b, (silent[0] != '\0') ? silent : "");
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}
