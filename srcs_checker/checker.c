/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/11 20:20:35 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ps_visual(t_stack *a, t_stack *b, t_deb vs)
//{
//
//}
//
//void	show_sw(t_stack *st, t_deb *vs)
//{
//
//}

static	void	implement(t_stack **st, t_deb vs)
{
	t_stack		*b;
	char 		*l;

	b = 0;
	l = 0;
	while (vs.oper)
	{
		ft_operations(st, &b, vs.oper->nb);
//		if (vs.visual)
//			ps_visual(*st, b, vs);
//		if (vs.sw)
//			show_sw(*st, vs);
		if (vs.sbys && get_next_line(1, &l))
			free(l);
		vs.oper = vs.oper->next;
	}
}

static	int 	opertoi(char *s)
{
	if (!ft_strcmp(s, "sa"))
		return (1);
	if (!ft_strcmp(s, "sb"))
		return (2);
	if (!ft_strcmp(s, "ss"))
		return (3);
	if (!ft_strcmp(s, "pa"))
		return (4);
	if (!ft_strcmp(s, "pb"))
		return (5);
	if (!ft_strcmp(s, "ra"))
		return (6);
	if (!ft_strcmp(s, "rb"))
		return (7);
	if (!ft_strcmp(s, "rr"))
		return (8);
	if (!ft_strcmp(s, "rra"))
		return (9);
	if (!ft_strcmp(s, "rrb"))
		return (10);
	if (!ft_strcmp(s, "rrr"))
		return (11);
	free(s);
	return (0);
}
static	int		crtvisoper(t_deb *vis, char *ln, int i)
{
	t_stack		*tm;

	get_next_line(0, &ln);
	if (!(i = opertoi(ln)) || !(vis->oper = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	tm = vis->oper;
	tm->nb = i;
	free(ln);
	while (get_next_line(0, &ln))
	{
		if (!(i = opertoi(ln)) ||
			!(tm->next = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		tm = tm->next;
		tm->nb = i;
		free(ln);
	}
	tm->next = 0;
	return (1);
}

int				main(int ac, char **av)
{
	t_stack		*st;
	t_deb		vis;

	st = 0;
	vis.steps = 0;
	vis.sbys = 0;
	vis.color = 0;
	vis.visual = 0;
	vis.oper = 0;
	vis.sw = 0;
	if (ac < 2)
		return (0);
	if (ft_reader(&st, &av[1], &vis, 0))
		exit(ft_printf("%sError\n", (vis.color ? RD : "")));
	if (!crtvisoper(&vis, 0, 0))
	{
		ft_printf("%sError\n", (vis.color ? RD : ""));
		ft_clearstack(st);
		return (0);
	}
	implement(&st, vis);
	return (0);
}
