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

#endif
