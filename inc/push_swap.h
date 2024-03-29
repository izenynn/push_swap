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

# include <shared.h>
# include <libft/ft_dlst.h>

// sort
void		handle_sort(t_global *tab, int n_cnt);

// sort small
void		sort_small(t_global *tab, int n_cnt);
void		smart_push(t_global *tab);
void		sort_a(t_global *tab);

// sort big
void		sort_big(t_global *tab);
int			smart_rotate_b(t_global *tab);

#endif
