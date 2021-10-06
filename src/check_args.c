/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:59:26 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/29 11:59:33 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_str.h>
#include <libft/ft_char.h>

static int	check_av_valid(int n_cnt, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < n_cnt)
	{
		j = -1;
		if (av[i][0] == '-' || av[i][0] == '+')
			j++;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
		}
	}
	return (0);
}

static int	check_is_int(char *s)
{
	int		len;
	short	is_neg;
	short	sign;

	sign = 0;
	is_neg = 0;
	len = ft_strlen(s);
	if (*s == '-' && ++is_neg && ++sign)
		len--;
	else if (*s == '+' && len--)
		sign = 1;
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	if (!sign && !is_neg && ft_strncmp(s, "2147483648", 10) >= 0)
		return (1);
	else if (sign && !is_neg && ft_strncmp(s + 1, "2147483648", 10) >= 0)
		return (1);
	else if (sign && is_neg && ft_strncmp(s + 1, "2147483649", 10) >= 0)
		return (1);
	return (0);
}

int	check_args(int n_cnt, char **nbrs)
{
	int	i;

	if (check_av_valid(n_cnt, nbrs))
		return (1);
	i = -1;
	while (++i < n_cnt)
	{
		if (check_is_int(nbrs[i]))
			return (1);
	}
	return (0);
}