/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:20:54 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/15 00:22:05 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include <libft/ft_dlst.h>

typedef struct s_global
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*head_a;
	t_dlist	*head_b;
	int		a_sz;
	int		b_sz;
}	t_global;

// handle args
int			handle_args(int ac, char **av, int **arr);
int			check_args(char **nbrs);

// stacks
t_global	*create_stack(void);
void		free_tab(t_global *tab);
int			initialise_tab(t_global *tab, int *arr, int n);

// rules
void		sa(t_global *tab);
void		sb(t_global *tab);
void		ss(t_global *tab);
void		pa(t_global *tab);
void		pb(t_global *tab);
void		ra(t_global *tab);
void		rb(t_global *tab);
void		rr(t_global *tab);
void		rra(t_global *tab);
void		rrb(t_global *tab);
void		rrr(t_global *tab);

#endif
