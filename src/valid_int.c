/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:30:16 by llopez            #+#    #+#             */
/*   Updated: 2018/07/17 03:53:35 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			neg_or_po(char *intmax, char *str)
{
	int	i;

	i = 0;
	if (!ft_strcmp(intmax, str))
		return (1);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (str[i] > intmax[i])
			return (0);
		i++;
	}
	return (1);
}

int			valid_int(char *str)
{
	int		i;
	char	intmax[13];

	ft_strcpy(&intmax[0], "2147483647");
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
		return (neg_or_po(intmax, &str[i]));
	}
	return (1);
}
