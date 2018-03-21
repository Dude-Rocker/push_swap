/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:31 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/21 23:36:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	while_more_third(t_stack **a, t_stack **b, t_mos sm, t_mos ms)
{
	int			res;

	res = src_place(*b, a[0]->nb, &sm);
	src_more_small(&ms, *a, a[0]->nb);
	if (ms.less - 2 < (ms.more / 4) && !res)
		res = 5;
	else if (ms.less - 2 < (ms.more / 4))
		res = (res == 1 ? 10 : 7);
	else
	{
		if (!src_most(*a, sm, ms))
			res = src_frs_less(*a, *b, &sm, &ms);
		else
			res = src_sec_less(*a, *b, &sm, &ms);
	}
	ft_operations(a, b, res);
	print_oper(res, 1);
}

static	void	ps_algo(t_stack *a, t_stack *b, t_mos sm, t_mos ms)
{
	int			res;

	while (a->next->next->next)
		while_more_third(&a, &b, sm, ms);
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
		res = src_max_b(b, ms, 1);
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
		exit(ft_printf("Error\n"));
	if (!check_order(st, 0))
		return (0);
	if (count_val_st(st) == 2)
		ft_printf("sa\n");
	else
		ps_algo(st, 0, ms, ms);
	return (0);
}
