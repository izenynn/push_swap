/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:13:31 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 11:13:33 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	shift(t_dlist **head)
{
	if (ft_dlstsize(*head) < 2)
		return (1);
	*head = (*head)->next;
	(*head)->prev->prev = ft_dlstlast(*head);
	(*head)->prev->next = NULL;
	(*head)->prev->prev->next = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	ra(t_global *tab)
{
	if (shift(&tab->head_a))
		return ;
	ft_printf("ra\n");
}

void	rb(t_global *tab)
{
	if (shift(&tab->head_b))
		return ;
	ft_printf("rb\n");
}

void	rr(t_global *tab)
{
	int	print;

	print = 1;
	if (shift(&tab->head_a))
		print = 0;
	if (shift(&tab->head_b))
		print = 0;
	if (print)
		ft_printf("rr\n");
}