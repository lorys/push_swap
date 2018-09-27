/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:30:16 by llopez            #+#    #+#             */
/*   Updated: 2018/09/27 14:31:00 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			valid_int(char *str)
{
	int		nb;
	int		intlen;
	char	*str_tmp;

	nb = ft_atoi(str);
	str_tmp = NULL;
	intlen = (str[0] == '-') ? 1 : 0;
	while (ft_isdigit(str[intlen]))
		intlen++;
	str_tmp = ft_itoa(nb);
	if (!ft_strncmp(str_tmp, str, intlen))
	{
		free(str_tmp);
		return (1);
	}
	free(str_tmp);
	return (0);
}
