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

int	is_sorted(t_dlist *head)
{
	while (head->next)
	{
		if (*(int *)head->data > *(int *)head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

void	handle_sort(int n_cnt, t_global *tab)
{
	if (n_cnt < 2 || is_sorted(tab->head_a))
		return ;
	if (n_cnt <= 5)
		sort_small(n_cnt, tab);
		
	else if (n_cnt == 3)
		sort_small(n_cnt, tab);
}
