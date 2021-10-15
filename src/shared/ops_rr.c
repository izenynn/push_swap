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
#include <libft/ft_printf.h>

static int	reverse_rotate(t_dlist **head, int sz)
{
	if (!*head)
		return (1);
	if (sz < 2)
		return (1);
	(*head)->prev = ft_dlstlast(*head);
	(*head)->prev->prev->next = NULL;
	(*head)->prev->next = *head;
	*head = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	rra(t_global *tab, int print)
{
	if (reverse_rotate(&tab->head_a, tab->a_sz))
		return ;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_global *tab, int print)
{
	if (reverse_rotate(&tab->head_b, tab->b_sz))
		return ;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_global *tab, int print)
{
	int	exec;

	exec = 2;
	if (reverse_rotate(&tab->head_a, tab->a_sz))
		exec--;
	if (reverse_rotate(&tab->head_b, tab->b_sz))
		exec--;
	if (print && exec)
		ft_printf("rrr\n");
}
