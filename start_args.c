/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:40:39 by marvin            #+#    #+#             */
/*   Updated: 2022/10/06 17:40:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_args(int argc, char **argv, t_args *args)
{
    if (argc < 5 || argc > 6)
        ft_error("Wrong number of parameters!\n");
    args->number_of_philosophers = ft_atol(argv[1]);
    args->time_to_die = ft_atol(argv[2]);
    args->time_to_eat = ft_atol(argv[3]);
    args->time_to_sleep = ft_atol(argv[4]);
    if (args->number_of_philosophers <= 0 || args->time_to_die < 0
        || args->time_to_eat < 0 || args->time_to_sleep < 0)
		ft_error("Invalid values!\n");
    if (argc == 6)
	{
		args->number_of_meals = ft_atoi(argv[4]);
		if (args->number_of_meals <= 0)
			ft_error("Invalid values!\n");
	}
	else
		args->number_of_meals = 0;
	//args->start_time = time_ms();
}
