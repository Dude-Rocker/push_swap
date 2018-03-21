/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:45:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/19 00:35:18 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	first_oper(t_stack *a, t_stack *b, int i)
{
	ft_printf("%sRed:     jump from one stack to another\n\n", RR);
	if (!a)
		ft_printf("%s%16c ", WT, '|');
	else if ((!a->next && i != 5 && i != 4) || i == 2 || i == 7 || i == 10)
		ft_printf("%s%14d | ", WT, a->nb);
	else if (i == 1 || i == 3)
		ft_printf("%s%14d %s| ", BL, a->nb, WT);
	else if (i == 9 || i == 11)
		ft_printf("%s%14d %s| ", GR, a->nb, WT);
	else if (i == 6 || i == 8 || i == 5)
		ft_printf("%s%14d %s| ", YL, a->nb, WT);
	else
		ft_printf("%s%14d %s| ", RR, a->nb, WT);
	if (!b)
		write(1, "\n", 1);
	else if ((!b->next && i != 5 && i != 4) || i == 1 || i == 9 || i == 6)
		ft_printf("%s%d\n", WT, b->nb);
	else if (i == 2 || i == 3)
		ft_printf("%s%d\n", BL, b->nb);
	else if (i == 10 || i == 11)
		ft_printf("%s%d\n", GR, b->nb);
	else if (i == 7 || i == 8 || i == 4)
		ft_printf("%s%d\n", YL, b->nb);
	else
		ft_printf("%s%d\n", RR, b->nb);
}

static	void	secon_oper(t_stack **a, t_stack **b, int i)
{
	a[0] = (a[0] ? a[0]->next : a[0]);
	b[0] = (b[0] ? b[0]->next : b[0]);
	if (!a[0] && !b[0])
		return ;
	if (!a[0])
		ft_printf("%s%16c ", WT, '|');
	else if (i == 1 || i == 3)
		ft_printf("%s%14d %s| ", BL, a[0]->nb, WT);
	else if (!a[0]->next && (i == 6 || i == 8))
		ft_printf("%s%14d %s| ", RD, a[0]->nb, WT);
	else if (i == 6 || i == 8 || i == 9 || i == 11 || i == 5 || i == 4)
		ft_printf("%s%14d %s| ", YL, a[0]->nb, WT);
	else
		ft_printf("%s%14d | ", WT, a[0]->nb);
	if (!b[0])
		write(1, "\n", 1);
	else if (i == 2 || i == 3)
		ft_printf("%s%d\n", BL, b[0]->nb);
	else if (!b[0]->next && (i == 7 || i == 8))
		ft_printf("%s%d\n", RD, b[0]->nb);
	else if (i == 7 || i == 8 || i == 4 || i == 5 || i == 10 || i == 11)
		ft_printf("%s%d\n", YL, b[0]->nb);
	else
		ft_printf("%s%d\n", WT, b[0]->nb);
	a[0] = (a[0] ? a[0]->next : a[0]);
}

static	void	vis_color(t_stack *a, t_stack *b, int i)
{
	ft_printf("%sWhite:   did'n move\n%sBlue:    exchanged places\n", WT, BL);
	ft_printf("%sYellow:  moved due to another operation\n", YL);
	ft_printf("%sGreen:   moved upward\n%sPurple:  moved down\n", GR, RD);
	first_oper(a, b, i);
	secon_oper(&a, &b, i);
	while ((b = (b ? b->next : b)) || a)
	{
		if (!a)
			ft_printf("%s%16c ", WT, '|');
		else if (!a->next && (i == 6 || i == 8))
			ft_printf("%s%14d %s| ", RD, a->nb, WT);
		else if (i == 6 || i == 8 || i == 9 || i == 11 || i == 5 || i == 4)
			ft_printf("%s%14d %s| ", YL, a->nb, WT);
		else
			ft_printf("%s%14d | ", WT, a->nb);
		if (!b)
			write(1, "\n", 1);
		else if (!b->next && (i == 7 || i == 8))
			ft_printf("%s%d\n", RD, b->nb);
		else if (i == 7 || i == 8 || i == 4 || i == 5 || i == 10 || i == 11)
			ft_printf("%s%d\n", YL, b->nb);
		else
			ft_printf("%s%d\n", WT, b->nb);
		a = (a ? a->next : a);
	}
}

void			ps_visual(t_stack *a, t_stack *b, t_deb vs)
{
	if (vs.sbys && !vs.debug)
		get_next_line(1, 0);
	if (vs.sbys || vs.debug)
		system("clear");
	if (vs.color)
	{
		vis_color(a, b, vs.oper->nb);
		ft_printf("%s%12c__   ___\n%13c     b\n\n", WT, '_', 'a');
		return ;
	}
	while (a || b)
	{
		ft_printf("\n");
		if (a && ft_printf("%14d | ", a->nb))
			a = a->next;
		else
			ft_printf("%16c ", '|');
		if (b)
		{
			ft_printf("%-d", b->nb);
			b = b->next;
		}
	}
	ft_printf("\n%12c__   ___\n%13c     b\n\n", '_', 'a');
}

void			ft_debuger(t_stack **a, t_stack *b, t_deb vs, int sum)
{
	char 		*ln;
	int 		i;

	ps_visual(*a, b, vs);
	ft_printf("write operation (or \"exit\" to exit): ");
	while (get_next_line(1, &ln))
	{
		if (!ft_strcmp(ln, "exit"))
			break ;
		if (!(i = opertoi(ln)))
			ft_printf("%s\nThere is no such command!: ", vs.color ? RR : "");
		else if (++sum)
		{
			ft_operations(a, &b, i);
			ps_visual(*a, b, vs);
			ft_printf("write operation (or \"exit\" to exit): ");
			free(ln);
		}
	}
	free(ln);
	if (vs.steps)
		ft_printf("%sTotal swap-operation: %s%d\n", (vs.color ? YL : ""),
			(vs.color ? BL : ""), sum);
	i = (!b && !check_order(*a, 0) ? 1 : 0);
	ft_printf("%s%s", (vs.color && i ? GR : ""), (vs.color && !i ? RR : ""));
	exit(ft_printf("%s\n", i ? "OK" : "KO"));
}
