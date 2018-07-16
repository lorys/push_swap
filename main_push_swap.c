/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:21:21 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:19:45 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	a_list *a;
	a_list *b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!good_params(argv, argc, 0))
		handle_errors();
	if (argc == 2 && ft_nbrnbr(argv[1]) < 2)
		return (0);
	fill_list(&a, argv, argc, 0);
	if (!valid_op(a))
		handle_errors();
	if (sorted(&a) || a_listlen(a) <= 1)
		return (0);
	prepare_sort(&a, &b);
	return (0);
}
