/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:02:03 by llopez            #+#    #+#             */
/*   Updated: 2018/05/11 20:14:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <libft.h>

typedef struct		arg_list
{
	int				null;
	int				content;
	struct arg_list *next;
	struct arg_list *prev;
}					a_list;

a_list				*list_top(a_list *lst);
a_list				*list_bottom(a_list *lst);
void				sx(a_list **x);
void				ss(a_list **a, a_list **b);
void				px(a_list *to, a_list **from);
void				ra(a_list *a);
void				rb(a_list *b);
void				rr(a_list *a, a_list *b);
void				rra(a_list *a);
void				rrb(a_list *b);
void				rrr(a_list *a, a_list *b);

#endif
