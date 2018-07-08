/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:02:03 by llopez            #+#    #+#             */
/*   Updated: 2018/07/08 00:20:22 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <libft.h>
# include <stdio.h>
# include "libft/ft_printf.h"

typedef struct		arg_list
{
	int				content;
	struct arg_list *next;
	struct arg_list *prev;
}					a_list;

void		sx(a_list **x, char *silent);
void		ss(a_list **a, a_list **b, char *silent);
void		px(a_list **from, a_list **to, char *silent);
void		rx(a_list **x, char *silent);
void		rr(a_list **a, a_list **b, char *silent);
void		rrx(a_list **x, char *silent);
void		rrr(a_list **a, a_list **b, char *silent);
a_list		*get_minus(a_list **a);
int			a_listlen(a_list *a);
int			get_minus_int(a_list **a);
void		prepare_sort(a_list **a, a_list **b);
void		sort_insert(a_list **a, a_list **b, int silent);
void		quick_sort(a_list **a, a_list **b, a_list *medianes);

// A RETIRER
int system(const char *command);

#endif
