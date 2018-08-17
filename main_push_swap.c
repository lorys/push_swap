/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/08/17 13:10:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_lst *a;
	t_lst *b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!good_params(argv, argc, 0))
		handle_errors(NULL, NULL);
	if (argc == 2 && ft_nbrnbr(argv[1]) < 2)
		return (0);
	fill_list(&a, argv, argc, 0);
	if (!valid_op(a))
		handle_errors(a, b);
	if (sorted(&a) || t_lstlen(a) <= 1)
	{
		free_list(a);
		free_list(b);
		return (0);
	}
	prepare_sort(&a, &b);
	free_list(a);
	free_list(b);
	read(0, NULL, 1);
	return (0);
}
