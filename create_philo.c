/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:39:40 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 17:39:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    create_philo(t_args *args)
{
	int i;

	i = 0;
	args->philo = malloc(sizeof(t_philo) * args->number_of_philosophers);
	if (!args->philo)
		return ;
	while (i < args->number_of_philosophers)
	{
		pthread_mutex_init(&args->philo[i].fork, NULL);
		printf("%lld Mutex Init Fork %i\n", current_time(args), (i + 1));
		i++;
	}
	i = 0;
	while (i < args->number_of_philosophers)
	{
		args->philo[i].id = i;
		pthread_create(&args->philo[i].philo, NULL, &routine, &args);
		printf("%lld %i created!\n",current_time(args), (i + 1));
		i++;
	}
}
//usleep(1000);
