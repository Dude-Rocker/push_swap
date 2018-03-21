/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:50:17 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/22 00:18:35 by vgladush         ###   ########.fr       */
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

int			src_place(t_stack *st, int i, t_mos *ms)
{
	ms->less = 1;
	ms->cn = count_val_st(st);
	while (st && st->next)
	{
		if ((i > st->next->nb && i < st->nb) || (((i < st->next->nb && i <
		st->nb) || (i > st->nb && i > st->next->nb)) && st->next->nb > st->nb))
			break ;
		ms->less += 1;
		st = st->next;
	}
	if (!st || !st->next)
		return (0);
	return (ms->less > (ms->cn / 2) ? 1 : 2);
}

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

int			src_max_b(t_stack *st, t_mos ms, int i)
{
	ms.less = 0;
	ms.more = st->nb;
	ms.cn = count_val_st(st);
	st = st->next;
	while (st)
	{
		if (ms.more < st->nb)
		{
			ms.less = i;
			ms.more = st->nb;
		}
		i++;
		st = st->next;
	}
	if (!ms.less)
		return (4);
	return (ms.less < ms.cn / 2 ? 7 : 10);
}

int			src_frs_less(t_stack *a, t_stack *b, t_mos *am, t_mos *bm)
{
	t_stack	*buf;

	buf = a;
	bm->more = 0;
	while (a)
	{
		src_more_small(am, buf, a->nb);
		if (am->less - 2 < am->more / 4)
			break ;
		a = a->next;
		bm->more += 1;
	}
	am->cn = src_place(b, a->nb, bm);
	if (!am->cn)
		return (6);
	else if (am->cn == 2)
		return (8);
	if (bm->cn - bm->less > bm->less - bm->more)
		return (8);
	return (6);
}

int			src_sec_less(t_stack *a, t_stack *b, t_mos *am, t_mos *bm)
{
	t_stack	*buf;
	t_stack	*tmp;
	int 	i;

	i = 0;
	buf = a;
	bm->more = 0;
	tmp = a;
	while (a)
	{
		src_more_small(am, buf, a->nb);
		if (am->less - 2  < am->more / 4)
		{
			bm->more = i;
			tmp = a;
		}
		a = a->next;
		i++;
	}
	am->cn = src_place(b, tmp->nb, bm);
	if (!am->cn)
		return (9);
	else if (am->cn == 1)
		return (11);
	am->cn = count_val_st(buf) - bm->more;
	if (bm->cn - am->cn < bm->less * 2)
		return (11);
	return (9);
}
