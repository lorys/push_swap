/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:30:16 by llopez            #+#    #+#             */
/*   Updated: 2018/08/16 14:50:53 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			valid_int(char *str)
{
	int nb;
	int intlen;

	nb = ft_atoi(str);
	intlen = (str[0] == '-') ? 1 : 0;
	while (ft_isdigit(str[intlen]))
		intlen++;
	if (!ft_strncmp(ft_itoa(nb), str, intlen))
		return (1);
	return (0);
}
