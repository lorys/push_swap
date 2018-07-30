/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:02:03 by llopez            #+#    #+#             */
/*   Updated: 2018/07/17 01:02:25 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <libft.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_lst
{
	int				content;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

int					valid_op(t_lst *a);
int					valid_int(char *str);
int					good_params(char **data, int argc, int checker);
t_lst				*get_maillon(t_lst **lst, int i);
t_lst				*get_max(t_lst **a);
t_lst				*get_minus(t_lst **a);
int					get_mediane(t_lst *a);
int					get_mediane_range(t_lst *a, int len);
void				fill_list(t_lst **a, char **data, int size, int checker);
t_lst				*sort_list(t_lst *a);
int					t_lstlen(t_lst *a);
void				sx(t_lst **x, char *silent);
void				ss(t_lst **a, t_lst **b);
void				px(t_lst **from, t_lst **to, char *silent);
void				rx(t_lst **x, char *silent);
void				rr(t_lst **a, t_lst **b, char *silent);
void				rrx(t_lst **x, char *silent);
void				rrr(t_lst **a, t_lst **b, char *silent);
int					t_lstlen(t_lst *a);
int					sorted(t_lst **a);
void				prepare_sort(t_lst **a, t_lst **b);
void				sort_insert(t_lst **a);
void				quick_sort(t_lst **a, t_lst **b, int len);
void				quick_sort_rev(t_lst **a, t_lst **b);
void				fill_list(t_lst **a, char **data, int size, int bonus);
void				print_list(t_lst *a);
void				print_multiple_list(t_lst *a, t_lst *b);
int					sorted(t_lst **a);
int					ft_nbrnbr(char *str);
void				sort_logic(t_lst **a, t_lst **b);
t_lst				*lastoflist(t_lst **x);
int					get_position_int(t_lst **x, t_lst *y);
void				handle_errors(void);
void				free_list(t_lst *lst);

#endif
