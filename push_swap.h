/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:02:03 by llopez            #+#    #+#             */
/*   Updated: 2018/05/09 17:33:33 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <libft.h>

typedef struct		arg_list
{
	int				content;
	struct arg_list *next;
	struct arg_list *prev;
}					a_list;

void				sa(a_list *a);
void				sb(a_list *b);
void				ss(a_list *a, a_list *b);
void				pa(a_list *a, a_list *b);
void				pb(a_list *a, a_list *b);
void				ra(a_list *a);
void				rb(a_list *b);
void				rr(a_list *a, a_list *b);
void				rra(a_list *a);
void				rrb(a_list *b);
void				rrr(a_list *a, a_list *b);

#endif
