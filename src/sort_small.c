/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:23:23 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/10/08 12:27:03 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_small(int n_cnt, t_global *tab)
{
	if (n_cnt == 2)
		if (*(int *)tab->head_a->data > *(int *)tab->head_a->next->data)
			sa(tab);
	if (n_cnt == 3)
		return ;
	else
		return ;
}
