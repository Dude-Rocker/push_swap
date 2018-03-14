/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:31 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/14 15:22:10 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 		main(int ac, char **av)
{
	t_stack	*st;

	st = 0;
	if (ac < 2)
		return (0);
	if (ft_reader(&st, &av[1], 0, 0))
		exit(ft_printf("Error\n"));
	if (!check_order(st, 0))
		return (0);
	return (0);
}
