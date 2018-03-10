/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 16:30:22 by vgladush          #+#    #+#             */
/*   Updated: 2018/03/10 17:12:54 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define RD "\x1B[35m"
# define YL "\x1B[33m"
# define WT "\x1B[37m"
# define GR "\x1B[32m"
# define BL "\x1B[36m"

typedef struct 		s_stack;
{
	int 			nb;
	struct	s_stack	*next;
}					t_stack;

#endif
