/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:07:50 by llopez            #+#    #+#             */
/*   Updated: 2018/07/12 16:09:51 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	char	*line;
	a_list	*a;
	a_list	*b;
	int		bonus;

	bonus = (argc >= 2 && !ft_strcmp("-I", argv[1]));
	a = NULL;
	b = NULL;
	fill_list(&a, argv, argc);
	if (bonus)
		print_multiple_list(a, b);
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "sa"))
			sx(&a, "");
		else if (!ft_strcmp(line, "sb"))
			sx(&b, "");
		else if (!ft_strcmp(line, "ss"))
			ss(&a, &b, "");
		else if (!ft_strcmp(line, "ra"))
			rx(&a, "");
		else if (!ft_strcmp(line, "rb"))
			rx(&b, "");
		else if (!ft_strcmp(line, "rr"))
			rr(&a, &b, "");
		else if (!ft_strcmp(line, "rra"))
			rrx(&a, "");
		else if (!ft_strcmp(line, "rrb"))
			rrx(&b, "");
		else if (!ft_strcmp(line, "rrr"))
			rrr(&a, &b, "");
		else if (!ft_strcmp(line, "pa"))
			px(&b, &a, "");
		else if (!ft_strcmp(line, "pb"))
			px(&a, &b, "");
		if (bonus)
			print_multiple_list(a, b);
	}
	if (sorted(&a) && b == NULL)
		ft_printf("\n\033[42m OK \033[0m");
	else
		ft_printf("\n\033[41m KO \033[0m");
	return (0);
}
