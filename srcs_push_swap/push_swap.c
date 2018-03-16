/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:31 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/16 23:38:08 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	print_res(int i)
{
	if (i == 1)
		ft_printf("sa\n");
	else if (i == 2)
		ft_printf("sb\n");
	else if (i == 3)
		ft_printf("ss\n");
	else if (i == 4)
		ft_printf("pa\n");
	else if (i == 5)
		ft_printf("pb\n");
	else if (i == 6)
		ft_printf("ra\n");
	else if (i == 7)
		ft_printf("rb\n");
	else if (i == 8)
		ft_printf("rr\n");
	else if (i == 9)
		ft_printf("rra\n");
	else if (i == 10)
		ft_printf("rrb\n");
	else if (i == 11)
		ft_printf("rrr\n");
}

static	int		oper_chek(t_stack *st, t_stack *end, int i, t_mos ms)
{
	src_most_small(&ms, st);
	end = src_end(st);
	if (!end)
		return (11);
	if (i && st->nb < st->next->nb && st->nb < end->nb)
		return (5);
	else if (i && (st->nb < st->next->nb && st->nb > end->nb) || (st->nb
		> end->nb && st->nb > st->next->nb && st->next->nb < end->nb))
		return (6);
	else if (i)
		return (1);
	if (st->nb < end->nb)
		return (7);
	else if (st->nb < st->next->nb)
		return (2);
	return (4);
}

static	void	ps_algo(t_stack *a, t_stack *b, int *ab, t_mos ms)
{
	int 		res;

	while (check_order(a, 0) || b)
	{
		ab[0] = (!check_order(a, 0) ? 0 : oper_chek(a, 0, 1, ms));
		ab[1] = (!check_revorder(b, 0) ? 0 : oper_chek(b, 0, 0, ms));
		if (ab[0] == 11 && ab[1] == 11)
			res = 11;
		else if (ab[0] == 5 && ab[1] != 11)
			res = (ab[1] ? ab[1] : ab[0]);
		else if (ab[0] == 11)
			res = (ab[1] && ab[1] != 4 ? ab[1] + 1 : ab[0] - 2);
		else if ((ab[0] == 1 && ab[1] == 2) || (ab[0] == 6 && ab[1] == 7))
			res = ab[1] + 1;
		else if (ab[1] == 11)
			res = (ab[0] ? ab[0] + 2 : ab[1] - 1);
		else if (!ab[0] && !ab[1])
			res = 4;
		else
			res = (ab[0] ? ab[0] : ab[1]);
		ft_operations(&a, &b, res);
		print_res(res);
	}
}

int 			main(int ac, char **av)
{
	t_mos		ms;
	t_stack		*st;
	int 		ab[2];

	ab[0] = 0;
	ab[1] = 0;
	ms.less = 0;
	ms.more = 0;
	st = 0;
	if (ac < 2)
		return (0);
	if (ft_reader(&st, &av[1], 0, 0))
		exit(ft_printf("Error\n"));
	if (!check_order(st, 0))
		return (0);
	ps_algo(st, 0, ab, ms);
	return (0);
}
