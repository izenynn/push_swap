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

static int	create_int_arr(int **arr, char **args)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	//while (args[++i])
	//	n++;
	n = 2;
	*arr = (int *)malloc(sizeof(int) * n);
	if (!*arr)
		return (-1);
	i = -1;
	// TODO: quitar el + 1 de args cuando este bien parseado
	while (++i < n)
		(*arr)[i] = ft_atoi(args[i + 1]);
	return (n);
}

static int	check_repeat(int *arr, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
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
	int	n;

	if (ac < 2 || check_args(ac, av))
		return (-1);
	n = create_int_arr(arr, av);
	if (!*arr)
		return (-1);
	if (check_repeat(*arr, n))
	{
		free(*arr);
		return (-1);
	}
	return (n);
}

int	main(int ac, char **av)
{
	t_global	*tab;
	int	*arr;
	int	n;

	n = handle_args(ac, av, &arr);
	if (n < 1)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	tab = create_stack();
	// print arr (just for test purpouses)
	for (int i = 0; i < n - 1; i++)
		ft_printf("%5d", arr[i]);
	//
	if (initialise_tab(tab, arr, n))
		return (1);
	// TODO: inicializar los stacks con numeros entreo 0 y x
	// print tab (test purpouses)
	ft_printf("\n");
	tab->a = tab->head_a;
	while (tab->a)
	{
		ft_printf("%5d", *(int *)tab->a->content);
		tab->a = tab->a->next;
	}
	return (free_tab_return(tab));
	// TODO: mensaje de error cuando le pasas una rgumento invalido :)
}