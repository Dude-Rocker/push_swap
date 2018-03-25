/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:49:00 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/25 23:50:51 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

static	void	free_stack(t_stack *st)
{
	if (st && st->next)
		free_stack(st->next);
	if (st)
		free(st);
}

static	char	*ft_specjoin(char *s1, char *s2)
{
	size_t		i;
	char		*res;
	int			z;

	z = -1;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(i + 2)))
		return (0);
	res[ft_strlen(s1)] = ' ';
	res[i + 1] = '\0';
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	i++;
	while (s2[++z])
		res[i + z] = s2[z];
	free(s1);
	free(s2);
	return (res);
}

static	void	print_res_rmz(t_stack *rn)
{
	char 		*res;
	char 		*ps;

	ps = 0;
	res = ft_itoa(rn->nb);
	rn = rn->next;
	while (rn)
	{
		res = ft_specjoin(res, ft_itoa(rn->nb));
		rn = rn->next;
	}
	ft_putstr(res);
	write(1, "\n\n", 2);
	ps = ft_joinfree("push_swap ", res, 0);
	res = ft_joinfree(" | checker -cn ", res, 2);
	res = ft_joinfree(ps, res, 3);
	system(res);
	free(res);
	free_stack(rn);
}

static	int		check_rep(int d, t_stack *rn)
{
	while (rn->next)
	{
		if (d == rn->nb)
			return (0);
		rn = rn->next;
	}
	if (!(rn->next = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	rn = rn->next;
	rn->nb = d;
	rn->next = 0;
	return (1);
}

int 			main(int ac, char **av)
{
	int			i;
	int			r;
	t_stack		*rn;

	if (ac < 2 || (i = ft_atoi(av[1])) < 1)
		return (0);
	srand(time(NULL));
	ft_putstr("\x1B[1;34mRandom numbers:\x1B[1;31m\n\n");
	r = rand() * rand() * rand() * rand() / rand();
	if (!(rn = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	rn->nb = r;
	rn->next = 0;
	while (i > 1)
	{
		r = rand() * rand() * rand() * rand() / rand();
		if (check_rep(r, rn))
			i--;
	}
	print_res_rmz(rn);
	return (0);
}
