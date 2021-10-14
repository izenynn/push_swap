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
#include <libft/ft_printf.h>

static int	shift(t_dlist **head, int sz)
{
	if (!*head)
		return (1);
	if (sz < 2)
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
	if (shift(&tab->head_a, tab->a_sz))
		return ;
	ft_printf("ra\n");
}

void	rb(t_global *tab)
{
	if (shift(&tab->head_b, tab->b_sz))
		return ;
	ft_printf("rb\n");
}

void	rr(t_global *tab)
{
	int	print;

	print = 2;
	if (shift(&tab->head_a, tab->a_sz))
		print--;
	if (shift(&tab->head_b, tab->b_sz))
		print--;
	if (print)
		ft_printf("rr\n");
}
