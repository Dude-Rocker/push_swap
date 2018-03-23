/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:45:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/23 23:27:32 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	first_oper(t_stack *a, t_stack *b, int i)
{
	ft_putstr("\x1B[31mRed:    jump from one stack to another\n\n");
	if (!a)
		ft_printf("\x1B[37m%16c ", '|');
	else if ((!a->next && i != 5 && i != 4) || i == 2 || i == 7 || i == 10)
		ft_printf("\x1B[37m%14d | ", a->nb);
	else if (i == 1 || i == 3)
		ft_printf("\x1B[36m%14d \x1B[37m| ", a->nb);
	else if (i == 9 || i == 11)
		ft_printf("\x1B[32m%14d \x1B[37m| ", a->nb);
	else if (i == 6 || i == 8 || i == 5)
		ft_printf("\x1B[33m%14d \x1B[37m| ", a->nb);
	else
		ft_printf("\x1B[31m%14d \x1B[37m| ", a->nb);
	if (!b)
		write(1, "\n", 1);
	else if ((!b->next && i != 5 && i != 4) || i == 1 || i == 9 || i == 6)
		ft_printf("\x1B[37m%d\n", b->nb);
	else if (i == 2 || i == 3)
		ft_printf("\x1B[36m%d\n", b->nb);
	else if (i == 10 || i == 11)
		ft_printf("\x1B[32m%d\n", b->nb);
	else if (i == 7 || i == 8 || i == 4)
		ft_printf("\x1B[33m%d\n", b->nb);
	else
		ft_printf("\x1B[31m%d\n", b->nb);
}

static	void	secon_oper(t_stack **a, t_stack **b, int i)
{
	a[0] = (a[0] ? a[0]->next : a[0]);
	b[0] = (b[0] ? b[0]->next : b[0]);
	if (!a[0] && !b[0])
		return ;
	if (!a[0])
		ft_printf("\x1B[37m%16c ", '|');
	else if (i == 1 || i == 3)
		ft_printf("\x1B[36m%14d \x1B[37m| ", a[0]->nb);
	else if (!a[0]->next && (i == 6 || i == 8))
		ft_printf("\x1B[35m%14d \x1B[37m| ", a[0]->nb);
	else if (i == 6 || i == 8 || i == 9 || i == 11 || i == 5 || i == 4)
		ft_printf("\x1B[33m%14d \x1B[37m| ", a[0]->nb);
	else
		ft_printf("\x1B[37m%14d | ", a[0]->nb);
	if (!b[0])
		write(1, "\n", 1);
	else if (i == 2 || i == 3)
		ft_printf("\x1B[36m%d\n", b[0]->nb);
	else if (!b[0]->next && (i == 7 || i == 8))
		ft_printf("\x1B[35m%d\n", b[0]->nb);
	else if (i == 7 || i == 8 || i == 4 || i == 5 || i == 10 || i == 11)
		ft_printf("\x1B[33m%d\n", b[0]->nb);
	else
		ft_printf("\x1B[37m%d\n", b[0]->nb);
	a[0] = (a[0] ? a[0]->next : a[0]);
}

static	void	vis_color(t_stack *a, t_stack *b, int i)
{
	ft_putstr("\x1B[37mWhite:  did'n move\n\x1B[36mBlue:   exchanged places\n");
	ft_putstr("\x1B[33mYellow: moved due to another operation\n");
	ft_putstr("\x1B[32mGreen:  moved upward\n\x1B[35mPurple: moved down\n");
	first_oper(a, b, i);
	secon_oper(&a, &b, i);
	while ((b = (b ? b->next : b)) || a)
	{
		if (!a)
			ft_printf("\x1B[37m%16c ", '|');
		else if (!a->next && (i == 6 || i == 8))
			ft_printf("\x1B[35m%14d \x1B[37m| ", a->nb);
		else if (i == 6 || i == 8 || i == 9 || i == 11 || i == 5 || i == 4)
			ft_printf("\x1B[33m%14d \x1B[37m| ", a->nb);
		else
			ft_printf("\x1B[37m%14d | ", a->nb);
		if (!b)
			write(1, "\n", 1);
		else if (!b->next && (i == 7 || i == 8))
			ft_printf("\x1B[35m%d\n", b->nb);
		else if (i == 7 || i == 8 || i == 4 || i == 5 || i == 10 || i == 11)
			ft_printf("\x1B[33m%d\n", b->nb);
		else
			ft_printf("\x1B[37m%d\n", b->nb);
		a = (a ? a->next : a);
	}
}

void			ps_visual(t_stack *a, t_stack *b, t_deb vs)
{
	if (vs.sbys && !vs.debug)
		read(1, 0, 1);
	if (vs.sbys || vs.debug)
		system("clear");
	if (!vs.debug && vs.color)
	{
		vis_color(a, b, vs.oper->nb);
		ft_printf("\x1B[37m%12c__   ___\n%13c     b\n\n", '_', 'a');
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
	ft_putstr("write operation (or \"exit\" to exit): ");
	while (get_next_line(1, &ln))
	{
		if (!ft_strcmp(ln, "exit"))
			break ;
		if (!(i = opertoi(ln)))
			ft_putstr("\nThere is no such command!: ");
		else if (++sum)
		{
			ft_operations(a, &b, i);
			ps_visual(*a, b, vs);
			ft_putstr("write operation (or \"exit\" to exit): ");
			free(ln);
		}
	}
	free(ln);
	if (vs.steps)
		ft_printf("%sTotal swap-operation: %s%d\n", (vs.color ? YL : ""),
			(vs.color ? "\x1B[36m" : ""), sum);
	i = (!b && !check_order(*a, 0) ? 1 : 0);
	ft_printf("%s%s", (vs.color && i ? GR : ""), (vs.color && !i ? RR : ""));
	exit(ft_printf("%s\n", i ? "OK" : "KO"));
}
