/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:28:51 by llopez            #+#    #+#             */
/*   Updated: 2018/07/17 03:51:08 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_charintlen(char *str)
{
	int	i;

	i = 0;
	i += (str[i] == '-') ? 1 : 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

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
			b += (ft_isdigit(data[i][b])) ? ft_charintlen(&data[i][b]) : 1;
		}
		if ((int)ft_strlen(data[i]) != b)
			return (0);
		i++;
	}
	return (1);
}
