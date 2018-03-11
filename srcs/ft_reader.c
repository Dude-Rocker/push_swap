/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:52:47 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/11 20:14:05 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_clearstack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->next)
		ft_clearstack(stack->next);
	free(stack);
}

static	int 	ft_dup_int(t_stack *s, int i)
{
	while (s->next)
	{
		if (s->nb == i)
			return (1);
		s = s->next;
	}
	return (0);
}

static	t_stack	*ft_crtstack(char *s, int i)
{
	t_stack		*res;
	int 		dig;

	dig = ft_atoi(s);
	if (*s == '-' || *s == '+')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] || ft_strlen(s) > 11 || (ft_strlen(s) > 2 && (dig == -1 || !dig)))
		return (0);
	if (!(res = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	res->nb = dig;
	res->next = 0;
	return (res);
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
		else
			return (0);
		s++;
	}
	return (1);
}

int				ft_reader(t_stack **st, char **s, t_deb *vis, int i)
{
	t_stack		*tmp;

	tmp = 0;
	while (vis && s[i][0] == '-' && !ft_isdigit(s[i][1]))
	{
		if (!ft_crtvis(vis, s[i++]))
			return (1);
		if (!s[i])
			exit(1);
	}
	if (!(tmp = ft_crtstack(s[i++], 0)))
		return (1);
	*st = tmp;
	while (s[i])
	{
		if (!(tmp->next = ft_crtstack(s[i++], 0)) || ft_dup_int(*st, tmp->next->nb))
		{
			ft_clearstack(*st);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
