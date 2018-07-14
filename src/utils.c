/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 05:09:18 by llopez            #+#    #+#             */
/*   Updated: 2018/07/14 19:41:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_nbrnbr(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			nb++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	return (nb);
}

int		valid_op(a_list *a)
{
	a_list *tma;
	a_list *tmb;

	tma = a;
	while (tma != NULL)
	{
		tmb = a;
		while (tmb != NULL)
		{
			if (tmb->content == tma->content && tmb != tma)
				return (0);
			tmb = tmb->next;
		}
		tma = tma->next;
	}
	return (1);
}

int		good_params(char **data, int argc, int checker)
{
	int i;
	int	b;

	i = 1;
	(void)b;
	if (checker && argc == 2 && ft_nbrnbr(data[1]) == 0)
		return (0);
	if (argc < 2)
		return (0);
	if (!strcmp(data[i], "-v") && checker)
		i++;
	while (i < argc)
	{
		b = 0;
		while (ft_isdigit(data[i][b]) || data[i][b] == '-' \
				|| data[i][b] == ' ' || data[i][b] == '\t')
		{
			if ((ft_isdigit(data[i][b]) || data[i][b] == '-')\
					&& !valid_int(&data[i][b]))
				return (0);
			b++;
		}
		if (ft_strlen(data[i]) != b)
			return (0);
		i++;
	}
	return (1);
}

void		print_multiple_list(a_list *a, a_list *b)
{
	system("clear");
	printf("%10s%20s\n", "LIST A", "LIST B");
	if (a == NULL)
		printf("(null)");
	if (b == NULL)
		printf("%20s\n", "(null)");
	while (b != NULL || a != NULL)
	{
		if (a != NULL)
			printf("%10d", a->content);
		else
			printf("%10s", "");
		if (b != NULL)
			printf("%20d", b->content);
		else
			printf("%10s", "");
		printf("\n");
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
	usleep(80000);
}

void		print_list(a_list *a)
{
	if (a == NULL)
		printf("(null)\n");
	while (a != NULL)
	{
		ft_printf("addr %p\n", a);
		ft_printf("%d\n", a->content);
		ft_printf("next = %p\n", a->next);
		ft_printf("prev = %p\n", a->prev);
		a = a->next;
	}
}

int			valid_int(char *str)
{
	int		i;
	char	*intmax;
	char	*intmin;

	intmax = ft_strdup("2147483647");
	intmin = ft_strdup("–2147483648");
	i = 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		i++;
	if (i > 11)
		return (0);
	else if (i == 10 || i == 11)
	{
		i = 0;
		if (str[i] == '-')
			i++;
		while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		{
			if (str[i] > intmax[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void		fill_list(a_list **a, char **data, int size, int checker)
{
	int		i;
	int		b;
	a_list	*tmp;

	tmp = NULL;
	i = 1;
	if (!ft_strcmp(data[i], "-v") && checker)
		i++;
	while (i < size)
	{
		b = 0;
		if ((ft_isdigit(data[i][b]) || data[i][b] == '-') && \
				!ft_strchr(data[i], ' ') && !ft_strchr(data[i], '\t') \
				&& valid_int(&data[i][b]))
		{
			*a = (a_list *)malloc(sizeof(a_list));
			(*a)->prev = tmp;
			if (tmp != NULL)
				(*a)->prev->next = *a;
			(*a)->next = NULL;
			(*a)->content = ft_atoi(data[i]);
			tmp = *a;
			*a = (*a)->next;
		}
		else
		{
			while (data[i][b])
			{
				if (data[i][b] == '\t' || data[i][b] == ' ')
					b++;
				else if ((ft_isdigit(data[i][b]) || data[i][b] == '-') && \
						valid_int(&data[i][b]))
				{
					(*a) = (a_list *)malloc(sizeof(a_list));
					(*a)->prev = tmp;
					if (tmp != NULL)
						(*a)->prev->next = *a;
					(*a)->next = NULL;
					(*a)->content = ft_atoi(&data[i][b]);
					tmp = *a;
					*a = (*a)->next;
					b += ft_intlen(ft_atoi(&data[i][b]));
				}
				else
					b++;
			}
		}
		i++;
	}
	*a = tmp;
	while ((*a)->prev != NULL)
		*a = (*a)->prev;
}

int			a_listlen(a_list *a)
{
	int	length;

	length = 0;
	while (a != NULL)
	{
		a = a->next;
		length++;
	}
	return (length);
}

int			sorted(a_list **a)
{
	a_list *tmp;

	tmp = *a;
	if (a_listlen(tmp) == 1)
		return (1);
	while (tmp != NULL)
	{
		if (tmp->next != NULL && tmp->content > tmp->next->content)
			return (0);
		else if (tmp->next == NULL && tmp->content < tmp->prev->content)
			return (0);
			
		tmp = tmp->next;
	}
	return (1);
}
