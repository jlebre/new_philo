/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:02:48 by marvin            #+#    #+#             */
/*   Updated: 2022/10/01 17:02:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    check_all_int(char **argv)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	input = argv;
	input++;
	while (input[i])
	{
		j = 0;
		if (input[i][j] == '+' || input[i][j] == '-')
			j++;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]))
				ft_error("All parameters should be numeric!\n");
			j++;
		}
		i++;
	}
}

void    check_limits(char **argv)
{
	int			i;
	long long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			ft_error("At least one parameters is either too big or too small!\n");
		i++;
	}
}

void    check(char **argv)
{
	check_all_int(argv);
	check_limits(argv);
}
