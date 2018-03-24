/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:50:17 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/23 23:27:32 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		src_more_small(t_mos *ms, t_stack *st, int i)
{
	ms->less = 0;
	ms->more = 0;
	ms->cn = count_val_st(st);
	while (st)
	{
		if (st->nb > i)
			ms->more += 1;
		else
			ms->less += 1;
		st = st->next;
	}
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
	if ((!st || !st->next) && j == 1)
		return (4);
	if (!j)
		return (ms->less < ms->cn / 2 && st && st->next ? 8 : 7);
	else if (j == 2)
		return (ms->less > ms->cn / 2 && st && st->next ? 11 : 10);
	return (ms->less - 1 < ms->cn / 2 ? 6 : 9);
}

int 			src_updw_sp(t_stack *st, int i, t_mos ms, int j)
{
	int 		o;
	t_stack		*tm;

	o = 100;
	tm = st;
	while (st)
	{
		src_more_small(&ms, tm, st->nb);
		if (ms.less - 2 < (ms.more / 4))
			break ;
		i++;
		st = st->next;
	}
	st = tm;
	while (count_val_st(st) > 5)
		st = st->next;
	while (st)
	{
		src_more_small(&ms, tm, st->nb);
		if (ms.less - 2 < (ms.more / 4))
			o = j;
		j--;
		st = st->next;
	}
	return (i > o ? 1 : 0);
}

int			src_max_b(t_stack *st, t_mos *ms, int i, t_stack *a)
{
	t_stack		*tmp;
	t_stack		*buf;
	t_stack		*bt;
	int 		j;
	int o;

	tmp = st;
	j = 5;
	o = 100;
	while (st)
	{
		src_more_small(ms, tmp, st->nb);
		if (ms->more - 1 < (ms->less / 4))
			break ;
		i++;
		st = st->next;
	}
	if (!i)
		return (src_place(a, st->nb, ms, 1));
	bt = tmp;
	while (count_val_st(bt) > 5)
		bt = bt->next;
	buf = bt;
	while (bt)
	{
		src_more_small(ms, tmp, st->nb);
		if (ms->less - 2 < (ms->more / 4))
		{
			buf = bt;
			o = j;
		}
		j--;
		bt = bt->next;
	}
	if (i > o)
		return (src_place(a, buf->nb, ms, 2));
	return (src_place(a, st->nb, ms, 0));
}
