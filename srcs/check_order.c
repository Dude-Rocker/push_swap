/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:50:06 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/21 22:25:09 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 		check_order(t_stack *a, int i)
{
	if (!a || !a->next)
		return (0);
	i = a->nb;
	a = a->next;
	while (a)
	{
		if (a->nb > i)
			i = a->nb;
		else
			return (1);
		a = a->next;
	}
	return (0);
}

void		print_oper(int i, int j)
{
	if (i == 1)
		write(1, "sa", 2);
	else if (i == 2)
		write(1, "sb", 2);
	else if (i == 3)
		write(1, "ss", 2);
	else if (i == 4)
		write(1, "pa", 2);
	else if (i == 5)
		write(1, "pb", 2);
	else if (i == 6)
		write(1, "ra", 2);
	else if (i == 7)
		write(1, "rb", 2);
	else if (i == 8)
		write(1, "rr", 2);
	else if (i == 9)
		write(1, "rra", 3);
	else if (i == 10)
		write(1, "rrb", 3);
	else if (i == 11)
		write(1, "rrr", 3);
	if (j)
		write(1, "\n", 1);
}

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

int			src_place(t_stack *st, int i, t_mos *ms, int j)
{
	ms->less = 1;
	ms->cn = count_val_st(st);
	while (st && st->next)
	{
		if ((i < st->next->nb && i > st->nb) || (((i > st->next->nb && i >
		st->nb) || (i < st->nb && i < st->next->nb)) && st->next->nb < st->nb))
			break ;
		ms->less += 1;
		st = st->next;
	}
	if (!st || !st->next)
		return (4);
	if (!j)
		return (ms->less > (ms->cn / 2) ? 11 : 8);
	return (ms->less > (ms->cn / 2) ? 9 : 6);
}