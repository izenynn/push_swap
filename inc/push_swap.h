/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:44:03 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 10:44:35 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft/ft_dlst.h>
# include <libft/ft_printf.h>

typedef struct s_global
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*head_a;
	t_dlist	*head_b;
}	t_global;

// handle args
int			handle_args(int ac, char **av, int **arr);
int			check_args(int ac, char **av);

// stacks
t_global	*create_stack(void);
int			initialise_tab(t_global *tab, int *arr, int n);
void		free_tab(t_global *tab);

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

// sort
void		handle_sort(int n_cnt, t_global *tab);
void		sort_small(int n_cnt, t_global *tab);
int			is_sorted(t_dlist *head);
void		n_ops(void (*op)(t_global *), t_global *tab, int n);

#endif
