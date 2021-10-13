/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:45:51 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/08 11:46:22 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	handle_sort(t_global *tab, int n_cnt)
{
	if (n_cnt < 2 || is_sorted(tab->head_a))
		return ;
	if (n_cnt <= 5)
		sort_small(tab, n_cnt);
	else if (n_cnt <= 100)
		return ;
	else if (n_cnt <= 500)
		return ;
	else
		return ;
}