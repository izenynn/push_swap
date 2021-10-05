/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabilongo <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:24:16 by rabilongo         #+#    #+#             */
/*   Updated: 2021/09/29 17:24:26 by rabilongo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft/ft_dlst.h>
#include <libft/ft_mem.h>
#include <stdlib.h>

t_global	*create_stack()
{
	t_global	*tab;

	tab = (t_global *)ft_calloc(sizeof(t_global), 1);
	if (!tab)
		return (NULL);
	tab->head_a = NULL;
	tab->head_b = NULL;
	return (tab);
}

int	free_tab_return(t_global *tab)
{
	if (!tab)
		return (0);
	if (tab->head_a)
		ft_dlstclear(&tab->head_a, free);
	if (tab->head_b)
		ft_dlstclear(&tab->head_b, free);
	free(tab);
	return (0);
}

int	initialise_tab(t_global *tab, int *arr, int ac)
{
	int	cnt;
	int	i;
	int	j;
	int	*tmp;

	i = -1;
	while (++i < ac - 1)
	{
		tmp = (int *)malloc(sizeof(int));
		if (!tmp)
			return (1);
		cnt = 0;
		j = -1;
		while (++j < ac - 1)
			if (j != i && arr[j] < arr[i])
				cnt++;
		*tmp = cnt;
		ft_dlstadd_back(&tab->head_a, ft_dlstnew(tmp));
		tmp = NULL;
	}
	return (0);
}