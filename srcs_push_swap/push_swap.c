/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:31 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/15 23:14:11 by vgladush         ###   ########.fr       */
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

static	int		oper_chek(t_stack *st, t_stack *end, int i)
{
	end = src_end(st);
	if (!end)
		return (11);
	if (i)
	{
		if (st->nb < st->next->nb && st->nb < end->nb)
			return (5);
		else if ((st->nb < st->next->nb && st->nb > end->nb) || (st->nb >
			end->nb && st->nb > st->next->nb && st->next->nb < end->nb))
			return (6);
		else
			return (1);
	}
	if (st->nb < end->nb)
		return (7);
	else if (st->nb < st->next->nb)
		return (2);
	return (4);
}

static	void	ps_algo(t_stack *a, t_stack *b, int i, int j)
{
	int 		res;

	while (check_order(a, 0) || b)
	{
		i = (!check_order(a, 0) ? 0 : oper_chek(a, 0, 1));
		j = (!check_revorder(b, 0) ? 0 : oper_chek(b, 0, 0));
		if (i == 11 && j == 11)
			res = 11;
		else if (i == 5 && j != 11)
			res = (j ? j : i);
		else if (i == 11)
			res = (j && j != 4 ? j + 1 : i - 2);
		else if ((i == 1 && j == 2) || (i == 6 && j == 7))
			res = j + 1;
		else if (j == 11)
			res = (i ? i + 2 : j - 1);
		else if (!i && !j)
			res = 4;
		else
			res = (i ? i : j);
		ft_operations(&a, &b, res);
		print_res(res);
	}
}

int 			main(int ac, char **av)
{
	t_stack		*st;

	st = 0;
	if (ac < 2)
		return (0);
	if (ft_reader(&st, &av[1], 0, 0))
		exit(ft_printf("Error\n"));
	if (!check_order(st, 0))
		return (0);
	ps_algo(st, 0, 0, 0);
	return (0);
}
