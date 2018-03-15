/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:24:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/14 22:46:05 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*src_end(t_stack *st)
{
	t_stack		*end;

	if (!st || !st->next || !st->next->next)
		return (0);
	while (st)
	{
		end = st;
		st = st->next;
	}
	return (end);
}

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

int 		check_revorder(t_stack *b, int i)
{
	if (!b || !b->next)
		return (0);
	i = b->nb;
	b = b->next;
	while (b)
	{
		if (b->nb < i)
			i = b->nb;
		else
			return (1);
		b = b->next;
	}
	return (0);
}
