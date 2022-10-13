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

	pthread_mutex_lock(&args.eat);
	printf("%lli Eat, Sleep, Think %p\n", current_time(&args), i);
	pthread_mutex_unlock(&args.eat);
	//sleep(1);
	return (0);
}