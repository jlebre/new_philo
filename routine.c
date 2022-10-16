/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:00:28 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 18:00:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *i)
{
	t_args *args;

	args = i;
	printf("START_TIME: %lld\n", args->llstart_time);
	printf("START_TIME: %lld\n", args->time_to_die);
	printf("START_TIME: %lld\n", args->time_to_eat);
	printf("START_TIME: %lld\n", args->time_to_sleep);
	printf("START_TIME: %i\n", args->number_of_philosophers);
	pthread_mutex_init(&args->routine, NULL);
	pthread_mutex_lock(&args->routine);
	red("Locked\n");
	printf("%lld Eat, Sleep, Think\n", current_time(args));
	printf("START_TIME: %lld\n", args->llstart_time);
	green("Unlocked\n");
	pthread_mutex_unlock(&args->routine);
	return (0);
}

/*
	printf("CURRENT_TIME: %lld\n", get_time(args));
	printf("DIF_TIME: %lld\n", current_time(args));
	*/