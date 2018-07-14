/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:07:50 by llopez            #+#    #+#             */
/*   Updated: 2018/07/14 19:45:36 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	listen(a_list **a, a_list **b, int bonus)
{
	char	*line;

	if (bonus)
		print_multiple_list(*a, *b);
	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "sa"))
			sx(a, "");
		else if (!ft_strcmp(line, "sb"))
			sx(b, "");
		else if (!ft_strcmp(line, "ss"))
			ss(a, b, "");
		else if (!ft_strcmp(line, "ra"))
			rx(a, "");
		else if (!ft_strcmp(line, "rb"))
			rx(b, "");
		else if (!ft_strcmp(line, "rr"))
			rr(a, b, "");
		else if (!ft_strcmp(line, "rra"))
			rrx(a, "");
		else if (!ft_strcmp(line, "rrb"))
			rrx(b, "");
		else if (!ft_strcmp(line, "rrr"))
			rrr(a, b, "");
		else if (!ft_strcmp(line, "pa"))
			px(b, a, "");
		else if (!ft_strcmp(line, "pb"))
			px(a, b, "");
		else
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (bonus)
			print_multiple_list(*a, *b);
	}
}

int		main(int argc, char **argv)
{
	a_list	*a;
	a_list	*b;
	int		bonus;

	bonus = (argc >= 2 && !ft_strcmp("-v", argv[1]));
	a = NULL;
	b = NULL;
	if (!good_params(argv, argc, 1))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (ft_nbrnbr(argv[1 + bonus]) > 1)
	{
		fill_list(&a, argv, argc, 1);
		if (!valid_op(a))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		listen(&a, &b, bonus);
	}
	if (sorted(&a) && b == NULL)
		ft_printf("\033[42m OK \033[0m\n");
	else
		ft_printf("\033[41m KO \033[0m\n");
	return (0);
}
