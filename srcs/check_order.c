/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 23:50:06 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/17 22:40:39 by vgladush         ###   ########.fr       */
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
		ft_printf("sa");
	else if (i == 2)
		ft_printf("sb");
	else if (i == 3)
		ft_printf("ss");
	else if (i == 4)
		ft_printf("pa");
	else if (i == 5)
		ft_printf("pb");
	else if (i == 6)
		ft_printf("ra");
	else if (i == 7)
		ft_printf("rb");
	else if (i == 8)
		ft_printf("rr");
	else if (i == 9)
		ft_printf("rra");
	else if (i == 10)
		ft_printf("rrb");
	else if (i == 11)
		ft_printf("rrr");
	if (j)
		ft_printf("\n");
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
