/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:50:17 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/25 17:38:10 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		src_more_less(t_mos *ms, t_stack *st, int i)
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

int 		src_updw_sp(t_stack *st, int i, t_mos ms, int j)
{
	int 	o;
	t_stack	*tm;

	o = 100;
	tm = st;
	while (st)
	{
		src_more_less(&ms, tm, st->nb);
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
		src_more_less(&ms, tm, st->nb);
		if (ms.less - 2 < (ms.more / 4))
			o = j;
		j--;
		st = st->next;
	}
	return (i > o ? 1 : 0);
}

static	int src_mb_sec(t_stack *st, t_mos *ms, t_stack *pr, t_stack *a)
{
	t_stack	*buf;
	t_stack	*tmp;

	buf = st;
	tmp = st;
	while (count_val_st(buf) > 5)
		buf = buf->next;
	while (buf)
	{
		src_more_less(ms, st, buf->nb);
		if (ms->more - 1 < (ms->less / 4) && tmp->nb < buf->nb)
			tmp = buf;
		buf = buf->next;
	}
	if (pr->nb < tmp->nb)
		return (src_place(a, tmp->nb, ms, 2));
	return (0);
}

int			src_max_b(t_stack *st, t_mos *ms, int i, t_stack *a)
{
	t_stack	*tmp;

	tmp = st;
	while (st)
	{
		src_more_less(ms, tmp, st->nb);
		if (ms->more - 1 < (ms->less / 4))
			break ;
		i++;
		st = st->next;
	}
	if (i < 5)
		st = precis_fb(st, &i, st);
	if (!i)
		return (src_place(a, st->nb, ms, 1));
	if ((i = src_mb_sec(tmp, ms, st, a)))
		return (i);
	return (src_place(a, st->nb, ms, 0));
}
