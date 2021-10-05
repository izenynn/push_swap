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

#include <libft/ft_str.h>
#include <libft/ft_mem.h>
#include <libft/ft_lst.h>
#include <push_swap.h>

#include <libft/ft_printf.h>

static int	*create_int_arr(int ac, char **av)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (ac));
	if (!arr)
		return (NULL);
	i = 0;
	while (++i < ac)
		arr[i - 1] = ft_atoi(av[i]);
	arr[i - 1] = 0;
	return (arr);
}

static int	check_repeat(int *arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
			if (arr[i] == arr[j])
				return (1);
	}
	return (0);
}

static t_global *create_stack()
{
	t_global	*tab;

	tab = (t_global *)ft_calloc(sizeof(t_global), 1);
	if (!tab)
		return (NULL);
	tab->head_a = NULL;
	tab->head_b = NULL;
	return (tab);
}

int	handle_args(int ac, char **av, int **arr)
{
	if (ac < 2 || check_args(ac, av))
		return (1);
	*arr = create_int_arr(ac, av);
	if (!*arr)
		return (1);
	if (check_repeat(*arr))
	{
		free(*arr);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_global	*tab;
	int	*arr;

	if (handle_args(ac, av, &arr))
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		return (1);
	}
	tab = create_stack();
	// print arr (just for test purpouses)
	ft_printf("ARR: ");
	for (int i = 0; i < ac - 1; i++)
		ft_printf("%5d", arr[i]);
	//
	if (initialise_tab(tab, arr, ac))
		return (1);
	// print tab (test purpouses)
	ft_printf("\nTAB: ");
	tab->a = tab->head_a;
	while (tab->a)
	{
		ft_printf("%5d", *(int *)tab->a->content);
		tab->a = tab->a->next;
	}
	ft_printf("\n");
	//
	return (free_tab_return(tab));
}