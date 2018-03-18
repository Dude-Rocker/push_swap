/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:47 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/18 22:58:17 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_clearstack(t_stack *stack, int i, int j)
{
	if (j)
	{
		while (stack)
		{
			if (stack->nb == i)
				return (1);
			stack = stack->next;
		}
		return (0);
	}
	if (!stack)
		return (0);
	if (stack->next)
		ft_clearstack(stack->next, 0, 0);
	free(stack);
	return (0);
}

static	int		ft_crtvis(t_deb *vis, char *s)
{
	if (!*++s)
		return (0);
	while (*s)
	{
		if (*s == 'v')
			vis->visual = 1;
		else if (*s == 'c')
			vis->color = 1;
		else if (*s == 's')
			vis->sbys = 1;
		else if (*s == 'n')
			vis->steps = 1;
		else if (*s == 'o')
			vis->sw = 1;
		else if (*s == 'd')
			vis->debug = 1;
		else
			return (0);
		s++;
	}
	return (1);
}

static	int		checktrue(char *s, int d, t_stack *a, t_stack *b)
{
	int 		i;
	int 		j;

	i = ((s[0] == '+' || s[0] == '-') && s[1] ? 1 : 0);
	j = (*s == '+' ? 1 : 0);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] || ft_clearstack(a, d, 1) || ft_clearstack(b, d, 1))
	{
		ft_clearstack(a, 0, 0);
		ft_clearstack(b, 0, 0);
		return (0);
	}
	i = ft_strlen(s + j);
	if ((s[j] != '-' && (i > 10 || d < 0 || (i == 10 && s[j] > 50))) ||
		(s[j] == '-' && (i > 11 || d > 0 || (i == 11 && s[j + 1] > 50))))
	{
		ft_clearstack(a, 0, 0);
		ft_clearstack(b, 0, 0);
		return (0);
	}
	return (1);
}

static	t_stack	*ft_crtstack(char *s, t_stack *st, int u, t_stack *res)
{
	t_stack		*buf;
	int			dig;
	char		**arr;

	arr = ft_strsplit(s, ' ');
	while (arr[++u])
	{
		dig = ft_atoi(arr[u]);
		if (!checktrue(arr[u], dig, st, res))
			return (0);
		if (!res)
		{
			if (!(res = (t_stack *)malloc(sizeof(t_stack))))
				return (0);
			buf = res;
		}
		else
		{
			if (!(buf->next = (t_stack *)malloc(sizeof(t_stack))))
				return (0);
			buf = buf->next;
		}
		buf->nb = dig;
		buf->next = 0;
	}
	return (res);
}

int				ft_reader(t_stack **st, char **s, t_deb *vis, int i)
{
	t_stack		*tmp;

	while (vis && s[i][0] == '-' && !ft_isdigit(s[i][1]))
	{
		if (!ft_crtvis(vis, s[i++]))
			return (1);
		if (!s[i])
			exit(1);
	}
	if (!(*st = ft_crtstack(s[i++], *st, -1, 0)))
		return (1);
	tmp = *st;
	while (s[i])
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_crtstack(s[i++], *st, -1, 0)))
			return (1);
	}
	return (0);
}
