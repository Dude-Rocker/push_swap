/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:53:02 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/21 22:25:11 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# define RD "\x1B[35m"
# define YL "\x1B[33m"
# define RR "\x1B[31m"
# define WT "\x1B[37m"
# define GR "\x1B[32m"
# define BL "\x1B[36m"

typedef	struct		s_stack
{
	int				nb;
	struct	s_stack	*next;
}					t_stack;

typedef	struct		s_mos
{
	int 			more;
	int 			less;
	int 			cn;
}					t_mos;

typedef	struct		s_deb
{
	int				steps;
	int 			color;
	int 			sbys;
	int 			visual;
	int				sw;
	int 			debug;
	struct s_stack	*oper;
}					t_deb;

void				ft_operations(t_stack **a, t_stack **b, int i);
int					ft_reader(t_stack **st, char **s, t_deb *vis, int i);
int					ft_clearstack(t_stack *stack, int i, int j);
int 				check_order(t_stack *a, int i);
void				ps_visual(t_stack *a, t_stack *b, t_deb vs);
void				src_more_small(t_mos *ms, t_stack *st, int i);
int					count_val_st(t_stack *st);
int 				src_place(t_stack *st, int i, t_mos *ms);
int 				src_most(t_stack *st, t_mos ms, t_mos rh);
int					src_max_b(t_stack *st, t_mos ms, int i);
int					src_frs_less(t_stack *a, t_stack *b, t_mos *am, t_mos *bm);
void				print_oper(int i, int j);
void				ft_debuger(t_stack **a, t_stack *b, t_deb vs, int sum);
int					opertoi(char *s);
int					src_sec_less(t_stack *a, t_stack *b, t_mos *am, t_mos *bm);

#endif
