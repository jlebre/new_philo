/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:18:53 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:18:53 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *i)
{
	t_philo *philo;

	philo = (t_philo *)i;
	pthread_mutex_init(&philo->routine, NULL);
	pthread_mutex_lock(&philo->routine);
	red("Locked\n");
	printf("%lli Eat, Sleep, Think\n", current_time(philo->args));
	green("Unlocked\n");
	pthread_mutex_unlock(&philo->routine);
	return (NULL);
}

