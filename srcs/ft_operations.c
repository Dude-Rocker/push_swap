/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:57:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/10 17:09:21 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_operations(t_stack *dig, int i)
{
	if (i == 1)
		swap_sa(dig);
	else if (i == 2)
		swap_sb(dig);
	else if (i == 3)
		swap_ss(dig);
	else if (i == 4)
		swap_pa(dig);
	else if (i == 5)
		swap_pb(dig);
	else if (i == 6)
		swap_ra(dig);
	else if (i == 7)
		swap_rb(dig);
	else if (i == 8)
		swap_rr(dig);
	else if (i == 9)
		swap_rra(dig);
	else if (i == 10)
		swap_rrb(dig);
	else if (i == 11)
		swap_rrr(dig);
}
