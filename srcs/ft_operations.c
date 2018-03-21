/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:57:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/21 22:25:08 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap_sab(t_stack **a, t_stack **b, int i)
{
	t_stack		*tmp;

	if ((i == 1 || i == 3) && *a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = *a;
		*a = tmp;
	}
	if ((i == 2 || i == 3) && *b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp->next = *b;
		*b = tmp;
	}
}

static	void	swap_pab(t_stack **a, t_stack **b, int i)
{
	t_stack		*tmp;

	if ((i == 1 || i == 3) && *b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (i == 2 && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}

static	void	swap_rab(t_stack **a, t_stack **b, int i)
{
	t_stack		*tmp;

	if ((i == 1 || i == 3) && *a)
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;
		*a = (*a)->next;
		tmp->next->next = 0;
	}
	if ((i == 2 || i == 3) && *b)
	{
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		*b = (*b)->next;
		tmp->next->next = 0;
	}
}

static	void	swap_rrrab(t_stack **a, t_stack **b, int i)
{
	t_stack		*tmp;

	if ((i == 1 || i == 3) && *a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *a;
		*a = tmp->next;
		tmp->next = 0;
	}
	if ((i == 2 || i == 3) && *b && (*b)->next)
	{
		tmp = *b;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *b;
		*b = tmp->next;
		tmp->next = 0;
	}
}

void			ft_operations(t_stack **a, t_stack **b, int i)
{
	if (i == 1)
		swap_sab(a, b, 1);
	else if (i == 2)
		swap_sab(a, b, 2);
	else if (i == 3)
		swap_sab(a, b, 3);
	else if (i == 4)
		swap_pab(a, b, 1);
	else if (i == 5)
		swap_pab(a, b, 2);
	else if (i == 6)
		swap_rab(a, b, 1);
	else if (i == 7)
		swap_rab(a, b, 2);
	else if (i == 8)
		swap_rab(a, b, 3);
	else if (i == 9)
		swap_rrrab(a, b, 1);
	else if (i == 10)
		swap_rrrab(a, b, 2);
	else if (i == 11)
		swap_rrrab(a, b, 3);
}
