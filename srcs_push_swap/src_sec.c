/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_sec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:14:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/18 17:14:00 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*src_end(t_stack *st)
{
	t_stack	*end;

	if (!st || !st->next || !st->next->next)
		return (0);
	while (st)
	{
		end = st;
		st = st->next;
	}
	return (end);
}


int 		src_half_val(t_stack *st, int i, int step)
{
	int 	j;

	j = st->nb;
	st = st->next;
	while (i && step--)
	{
		if (st->nb > j)
			return (1);
		st = st->next;
	}
	while (!i && step--)
	{
		if (st->nb < j)
			return (1);
		st = st->next;
	}
	return (0);
}

t_stack		*src_define(t_stack *st, int i, int step)
{
	int		end;

	end = (i ? step : count_val_st(st) - step);
	while (end--)
		st = st->next;
	return (st);
}

int 		src_most(t_stack *st, t_mos ms, t_mos rh)
{
	int 	j;
	t_stack	*s;

	s = st;
	j = 0;
	while (st)
	{
		src_more_small(&ms, s, st->nb);
		if (ms.less - 2 < ms.more / 5)
			break ;
		st = st->next;
		j++;
	}
	rh.less = j;
	while (st)
	{
		src_more_small(&ms, s, st->nb);
		if (ms.less - 2 < ms.more / 5)
			rh.more = j;
		st = st->next;
		j++;
	}
	return (rh.less > ms.cn - rh.more ? 1 : 0);
}
