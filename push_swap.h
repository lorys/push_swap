/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:02:03 by llopez            #+#    #+#             */
/*   Updated: 2018/05/23 01:09:51 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <libft.h>
# include <stdio.h>

typedef struct		arg_list
{
	int				content;
	struct arg_list *next;
	struct arg_list *prev;
}					a_list;

void		sx(a_list **x);
void		ss(a_list **a, a_list **b);
void		px(a_list **from, a_list **to);
void		rx(a_list **x);
void		rr(a_list **a, a_list **b);
void		rrx(a_list **x);
void		rrr(a_list **a, a_list **b);
a_list		*get_minus(a_list **a);
int			a_listlen(a_list *a);
int			get_minus_int(a_list **a);


// A RETIRER
int system(const char *command);

#endif
