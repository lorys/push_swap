/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:28:51 by llopez            #+#    #+#             */
/*   Updated: 2018/07/17 04:05:07 by llopez           ###   ########.fr       */
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
	if (argc < 2)
		exit(0);
	if ((checker && argc == 2 && ft_nbrnbr(data[1]) == 0))
		return (0);
	i += (!strcmp(data[i], "-v") && checker) ? 1 : 0;
	while (i < argc)
	{
		b = 0;
		while (ft_isdigit(data[i][b]) || (data[i][b] == '-' && ft_isdigit(data[i][b + 1])) \
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
