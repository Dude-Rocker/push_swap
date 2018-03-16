/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:50:17 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/17 00:13:11 by vgladush         ###   ########.fr       */
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

int			count_val_st(t_stack *st)
{
	int 	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
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

void		src_most_small(t_mos *ms, t_stack *st)
{
	int 	i;

	ms->cn = count_val_st(st);
	i = st->nb;
	st = st->next;
	while (st)
	{
		if (st->nb > i)
			ms->more += 1;
		else
			ms->less += 1;
		st = st->next;
	}
}
