/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:03 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/25 23:43:30 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	show_sw(t_stack *s, int i, int c, int h)
{
	t_stack		*r;
	int			j;

	r = s;
	j = --i;
	while (j--)
		r = r->next;
	ft_printf("%sCurrent operation", (c ? YL : ""));
	if (h)
		ft_printf(" (%s%d%s)", (c ? GR : ""), i + 1, (c ? YL : ""));
	ft_printf(": %s", (c ? GR : ""));
	print_oper(r->nb, 0);
	if (i)
		ft_printf(" %sPrevious operations: %s", (c ? YL : ""), (c ? BL : ""));
	while (i--)
	{
		r = s;
		j = i;
		while (j--)
			r = r->next;
		print_oper(r->nb, 0);
		if (i)
			ft_printf(" %s<<< %s", (c ? YL : ""), (c ? BL : ""));
	}
	write(1, "\n", 1);
}

static	void	implement(t_stack **st, t_deb vs)
{
	t_stack		*b;
	t_stack		*shw;
	int			sum;

	b = 0;
	sum = 0;
	shw = vs.oper;
	while (vs.oper && ++sum)
	{
		ft_operations(st, &b, vs.oper->nb);
		if (vs.visual)
			ps_visual(*st, b, vs);
		if (vs.visual && vs.sw)
			show_sw(shw, sum, vs.color, vs.steps);
		vs.oper = vs.oper->next;
	}
	ft_clearstack(shw, 0, 0);
	if (vs.steps)
		ft_printf("%sTotal swap-operations: %s%d\n", (vs.color ? YL : ""),
			(vs.color ? BL : ""), sum);
	if (!b && !check_order(*st, 0))
		ft_printf("%sOK\n", (vs.color ? GR : ""));
	else
		ft_printf("%sKO\n", (vs.color ? RR : ""));
}

int				opertoi(char *s)
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

	if (!get_next_line(0, &ln))
	{
		free(ln);
		return (1);
	}
	if (!(i = opertoi(ln)) ||
		!(vis->oper = (t_stack *)malloc(sizeof(t_stack))))
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
	vis.debug = 0;
	if (ac < 2)
		return (0);
	if (ft_reader(&st, &av[1], &vis, 0))
		exit(ft_printf("%sError\n", (vis.color ? RD : "")));
	if (vis.debug)
		ft_debuger(&st, 0, vis, 0);
	else if (!crtvisoper(&vis, 0, 0))
	{
		ft_printf("%sError\n", (vis.color ? RD : ""));
		ft_clearstack(st, 0, 0);
		return (0);
	}
	implement(&st, vis);
	return (0);
}
