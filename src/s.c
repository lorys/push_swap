/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:04:58 by llopez            #+#    #+#             */
/*   Updated: 2018/05/27 17:37:25 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sx(a_list **x, char *silent)
{
	int		tmp;
	if (*x == NULL || (*x)->next == NULL)
		return;
	tmp = (*x)->content;
	(*x)->content = (*x)->next->content;
	(*x)->next->content = tmp;
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}

void		ss(a_list **a, a_list **b, char *silent)
{
	sx(a, (silent[0] != '\0') ? silent : "");
	sx(b, (silent[0] != '\0') ? silent : "");
	if (silent[0] != '\0')
		ft_printf("%s\n", silent);
}
