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

// sort
void		handle_sort(t_global *tab, int n_cnt);
void		n_ops(void (*op)(t_global *), t_global *tab, int n);
int			is_sorted(t_dlist *head);
int			is_nsorted(t_dlist *head, int n);
int			is_min(t_dlist *head, t_dlist *element);
int			is_max(t_dlist *head, t_dlist *element);

// sort small
void		sort_small(t_global *tab, int n_cnt);
void		smart_push(t_global *tab);
void		sort_a(t_global *tab);
int			get_ins_pos(t_dlist *head, int data);

#endif
