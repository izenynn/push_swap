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

static int	check_nbrs_valid(char **nbrs)
{
	int	i;
	int	j;

	i = -1;
	while (nbrs[++i])
	{
		j = -1;
		if (nbrs[i][0] == '-' || nbrs[i][0] == '+')
			j++;
		if (!ft_isdigit(nbrs[i][j + 1]))
			return (1);
		while (nbrs[i][++j])
		{
			if (!ft_isdigit(nbrs[i][j]))
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
	if (*s == '-' && ++is_neg && ++sign && s++)
		len--;
	else if (*s == '+' && ++sign && s++)
		len--;
	while (*s == '0' && *s && len--)
		s++;
	if (len > 10)
		return (1);
	else if (len < 10)
		return (0);
	if (!sign && !is_neg && ft_strncmp(s, "2147483648", 10) >= 0)
		return (1);
	else if (sign && !is_neg && ft_strncmp(s, "2147483648", 10) >= 0)
		return (1);
	else if (sign && is_neg && ft_strncmp(s, "2147483649", 10) >= 0)
		return (1);
	return (0);
}

int	check_args(char **nbrs)
{
	int	i;

	if (check_nbrs_valid(nbrs))
		return (1);
	i = -1;
	while (nbrs[++i])
	{
		if (check_is_int(nbrs[i]))
			return (1);
	}
	return (0);
}
