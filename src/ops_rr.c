/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:14:00 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 11:14:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	reverse_rotate(t_dlist **head)
{
	if (!*head)
		return (1);
	if (ft_dlstsize(*head) < 2)
		return (1);
	(*head)->prev = ft_dlstlast(*head);
	(*head)->prev->prev->next = NULL;
	(*head)->prev->next = *head;
	*head = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	rra(t_global *tab)
{
	if (reverse_rotate(&tab->head_a))
		return ;
	ft_printf("rra\n");
}

void	rrb(t_global *tab)
{
	if (reverse_rotate(&tab->head_b))
		return ;
	ft_printf("rrb\n");
}

void	rrr(t_global *tab)
{
	int	print;

	print = 1;
	if (reverse_rotate(&tab->head_a))
		print = 0;
	if (reverse_rotate(&tab->head_b))
		print = 0;
	if (print)
		ft_printf("rrr\n");
}
