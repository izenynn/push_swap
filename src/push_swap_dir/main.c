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

int	main(int ac, char **av)
{
	t_global	*tab;
	int			*arr;
	int			n_cnt;

	if (ac == 1)
		return (EXIT_SUCCESS);
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
	handle_sort(tab, n_cnt);
	free_tab(tab);
	return (EXIT_SUCCESS);
}
