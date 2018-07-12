/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:07:50 by llopez            #+#    #+#             */
/*   Updated: 2018/07/12 05:23:41 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	char	*line;
	a_list	*a;
	a_list	*b;

	a = NULL;
	b = NULL;
	fill_list(&a, argv, argc);
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "sa"))
			sx(&a, "");
		else if (ft_strcmp(line, "sb"))
			sx(&b, "");
		else if (ft_strcmp(line, "ss"))
			ss(&a, &b, "ss");
	}
	return (0);
}
