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
	t_args args;

	pthread_mutex_lock(&args.routine);
	printf("%lld Eat, Sleep, Think %p\n", current_time(&args), i);
	usleep(100000);
	printf("START_TIME: %lld\n", args.llstart_time);
	printf("CURRENT_TIME: %lld\n", get_time(&args));
	printf("DIF_TIME: %lld\n", current_time(&args));
	usleep(100000);
	pthread_mutex_unlock(&args.routine);
	return (0);
}