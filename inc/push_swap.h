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
	t_dlist *a;
	t_dlist *b;
	t_dlist *head_a;
	t_dlist *head_b;
}	t_global;


t_global	*create_stack();
int			check_args(int ac, char **av);
int			free_tab_return(t_global *tab);
int			initialise_tab(t_global *tab, int *arr, int n);

#endif
