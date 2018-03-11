/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:53:02 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/11 19:56:23 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# define RD "\x1B[35m"
# define YL "\x1B[33m"
# define WT "\x1B[37m"
# define GR "\x1B[32m"
# define BL "\x1B[36m"

typedef	struct		s_stack
{
	int				nb;
	struct	s_stack	*next;
}					t_stack;

typedef	struct		s_deb
{
	int				steps;
	int 			color;
	int 			sbys;
	int 			visual;
	int				sw;
	struct s_stack	*oper;
}					t_deb;

void				ft_operations(t_stack **a, t_stack **b, int i);
int					ft_reader(t_stack **st, char **s, t_deb *vis, int i);
void				ft_clearstack(t_stack *stack);

#endif
