/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:45:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/14 00:06:27 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	color_instr(t_stack *a, t_stack *b, int i)
{
	ft_printf("%sBlue:    exchanged places\n", BL);
	ft_printf("%sRed:     jump from one stack to another\n\n", RR);
	if (!a)
		ft_printf("%s%16c ", WT, '|');
	else if (a && ((!a->next && i != 4) || i == 2 || i == 7 || i == 10))
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
	else if (b && ((!b->next && i != 5) || i == 1 || i == 9 || i == 6))
		ft_printf("%s%d\n", WT, b->nb);
	else if (i == 2 || i == 3)
		ft_printf("%s%d\n", BL, b->nb, WT);
	else if (i == 10 || i == 11)
		ft_printf("%s%d\n", GR, b->nb, WT);
	else if (i == 7 || i == 8 || i == 4)
		ft_printf("%s%d\n", YL, b->nb);
	else
		ft_printf("%s%d\n", RR, b->nb);
}

static	void	vis_color(t_stack *a, t_stack *b, int i)
{
	ft_printf("%sWhite:   did'n move\n", WT);
	ft_printf("%sYellow:  moved due to another operation\n", YL);
	ft_printf("%sGreen:   moved upward\n%sPurple:  moved down\n", GR, RD);
	color_instr(a, b, i);
	a = (a ? a->next : a);
	b = (b ? b->next : b);
	if (!a && !b)
		return ;
	if (!a)
		ft_printf("%s%16c ", WT, '|');
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
	else if (b && ((!b->next && i != 5) || i == 1 || i == 9 || i == 6))
		ft_printf("%s%d\n", WT, b->nb);
	else if (i == 2 || i == 3)
		ft_printf("%s%d\n", BL, b->nb, WT);
	else if (i == 10 || i == 11)
		ft_printf("%s%d\n", GR, b->nb, WT);
	else if (i == 7 || i == 8 || i == 4)
		ft_printf("%s%d\n", YL, b->nb);
	else
		ft_printf("%s%d\n", RR, b->nb);
	while (a || b)
	{
		if (a)
		{
			ft_printf("%14d | ", a->nb);
			a = a->next;
		}
		else
			ft_printf("            | ");
		if (b)
		{
			ft_printf("%d", b->nb);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("%12c__   ___\n%13c     b\n\n", '_', 'a');
}

void			ps_visual(t_stack *a, t_stack *b, t_deb vs)
{
	if (vs.sbys)
	{
		sleep(1);
		system("clear");
	}
	ft_printf("\n");
	if (vs.color)
	{
		vis_color(a, b, vs.oper->nb);
		return ;
	}
	while (a || b)
	{
		if (a && ft_printf("%14d | ", a->nb))
			a = a->next;
		else
			ft_printf("            | ");
		if (b)
		{
			ft_printf("%-d", b->nb);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("%12c__   ___\n%13c     b\n\n", '_', 'a');
}

char			*tranfosh(int i)
{
	if (i == 1)
		return ("sa");
	if (i == 2)
		return ("sb");
	if (i == 3)
		return ("ss");
	if (i == 4)
		return ("pa");
	if (i == 5)
		return ("pb");
	if (i == 6)
		return ("ra");
	if (i == 7)
		return ("rb");
	if (i == 8)
		return ("rr");
	if (i == 9)
		return ("rra");
	if (i == 10)
		return ("rrb");
	if (i == 11)
		return ("rrr");
	return (0);
}
