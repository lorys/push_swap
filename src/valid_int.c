/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:30:16 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:30:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			valid_int(char *str)
{
	int		i;
	char	*intmax;
	char	*intmin;

	intmax = ft_strdup("2147483647");
	intmin = ft_strdup("–2147483648");
	i = 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		i++;
	if (i > 11)
		return (0);
	else if (i == 10 || i == 11)
	{
		i = 0;
		if (str[i] == '-')
			i++;
		while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		{
			if (str[i] > intmax[i])
				return (0);
			i++;
		}
	}
	return (1);
}
