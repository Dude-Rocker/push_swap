/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:57:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/10 17:37:22 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_operations(t_stack *dig, int i)
{
	if (i == 1)
		swap_ss(dig, 1);
	else if (i == 2)
		swap_ss(dig, 2);
	else if (i == 3)
		swap_ss(dig, 3);
	else if (i == 4)
		swap_pp(dig, 1);
	else if (i == 5)
		swap_pp(dig, 2);
	else if (i == 6)
		swap_rr(dig, 1);
	else if (i == 7)
		swap_rr(dig, 2);
	else if (i == 8)
		swap_rr(dig, 3);
	else if (i == 9)
		swap_rrr(dig, 1);
	else if (i == 10)
		swap_rrr(dig, 2);
	else if (i == 11)
		swap_rrr(dig, 3);
}
