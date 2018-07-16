/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:28:51 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:54:18 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		good_params(char **data, int argc, int checker)
{
	int i;
	int	b;

	i = 1;
	(void)b;
	if ((checker && argc == 2 && ft_nbrnbr(data[1]) == 0) || argc < 2)
		return (0);
	if (!strcmp(data[i], "-v") && checker)
		i++;
	while (i < argc)
	{
		b = 0;
		while (ft_isdigit(data[i][b]) || data[i][b] == '-' \
				|| data[i][b] == ' ' || data[i][b] == '\t')
		{
			if ((ft_isdigit(data[i][b]) || data[i][b] == '-')\
					&& !valid_int(&data[i][b]))
				return (0);
			b++;
		}
		if ((int)ft_strlen(data[i]) != b)
			return (0);
		i++;
	}
	return (1);
}
