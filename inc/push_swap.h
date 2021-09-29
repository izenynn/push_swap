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

# include <libft/ft_lst.h>

typedef struct s_global
{
	t_list *a;
	t_list *b;
	t_list *head_a;
	t_list *head_b;
}	t_global;


int	check_args(int ac, char **av);
int	free_tab_return(t_global *tab);
int	initialise_tab(t_global *tab, int *arr);

#endif
