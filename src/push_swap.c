/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:27:52 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 10:48:19 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

#pragma region tests

// REMOVE THIS FUNC IN FINAL VERSION
/*static void	show_arr_tab(int n, int *arr, t_global *tab)
{
	ft_printf("\n|---------------------------|\n");
	ft_printf("|     ARR     |      A      |\n");
	ft_printf("|---------------------------|\n");
	tab->a = tab->head_a;
	for (int i = 0; i < n; i++)
	{
		ft_printf("| %-12d|", arr[i]);
		if (tab->a)
		{
			ft_printf(" %-12d|\n", *(int *)tab->a->data);
			tab->a = tab->a->next;
		}
		else
			ft_printf(" (null)      |\n");
	}
	ft_printf("|---------------------------|\n\n");
}*/

/*static void	show_tab(int n, t_global *tab)
{
	int	a_sz;
	int	b_sz;

	a_sz = ft_dlstsize(tab->head_a);
	b_sz = ft_dlstsize(tab->head_b);
	ft_printf("\n|-------------|-------------|\n");
	ft_printf("|      A      |      B      |\n");
	ft_printf("|-------------|-------------|\n");
	tab->a = tab->head_a;
	tab->b = tab->head_b;
	for (int i = 0; i < n; i++)
	{
		if (tab->a && n - a_sz <= i)
		{
			ft_printf("| %-12d", *(int *)tab->a->data);
			tab->a = tab->a->next;
		}
		else
			ft_printf("|             ");
		if (tab->b && n - b_sz <= i)
		{
			ft_printf("| %-12d|\n", *(int *)tab->b->data);
			tab->b = tab->b->next;
		}
		else
			ft_printf("|             |\n");
	}
	ft_printf("|-------------|-------------|\n\n");
}*/

/*void	leaks(void)
{
	system("leaks -q push_swap");
}*/

#pragma endregion tests

int	main(int ac, char **av)
{
	t_global	*tab;
	int			*arr;
	int			n_cnt;

	// TESTS
	//atexit(leaks);
	//
	n_cnt = handle_args(ac, av, &arr);
	if (n_cnt < 0)
		return (EXIT_FAILURE);
	tab = create_stack();
	if (initialise_tab(tab, arr, n_cnt))
	{
		free(arr);
		return (EXIT_FAILURE);
	}
	free(arr);
	handle_sort(n_cnt, tab);
	free_tab(tab);
	return (EXIT_SUCCESS);
}
