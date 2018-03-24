/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:31 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/24 00:35:13 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_val_st(t_stack *st)
{
	int		i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

static	void	while_more_third(t_stack **a, t_stack **b, t_mos ms)
{
	int			res;
	t_stack		*s;

	s = *b;
	res = 0;
	src_more_small(&ms, *a, a[0]->nb);
	if (ms.less - 2 < (ms.more / 4))
		res = 5;
	else if (src_updw_sp(*a, 0, ms, 5))
		res = 9;
	else
	{
		if (s)
			res = s->nb;
		while (s && s->next)
			s = s->next;
		if (s && res < s->nb)
			res = 8;
		else
			res = 6;
	}
	ft_operations(a, b, res);
	print_oper(res, 1);
}

static	void	ps_algo(t_stack *a, t_stack *b, t_mos ms)
{
	int			res;

	while (a->next->next->next)
		while_more_third(&a, &b, ms);
	while (check_order(a, 0))
	{
		if (a->nb > a->next->nb && a->nb > a->next->next->nb)
			res = 6;
		else if (a->nb > a->next->nb && a->nb < a->next->next->nb)
			res = 1;
		else
			res = 9;
		ft_operations(&a, &b, res);
		print_oper(res, 1);
	}
	while (b)
	{
		res = src_max_b(b, &ms, 0, a);
		ft_operations(&a, &b, res);
		print_oper(res, 1);
	}
}

int				main(int ac, char **av)
{
	t_mos		ms;
	t_stack		*st;

	ms.less = 0;
	ms.more = 0;
	ms.cn = 0;
	st = 0;
	if (ac < 2)
		return (0);
	if (ft_reader(&st, &av[1], 0, 0))
		exit(write(1, "Error\n", 6));
	if (!check_order(st, 0))
		return (0);
	if (count_val_st(st) == 2)
		write(1, "sa\n", 3);
	else
		ps_algo(st, 0, ms);
	return (0);
}
