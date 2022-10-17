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
	while (1)
	{
		check_if_dead(philo);
		if (eat(philo))
			break ;
		if (nap(philo))
			break;
	}
	return (NULL);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	printf("%lld %i is eating\n", current_time(philo->args), philo->id);
	pthread_mutex_unlock(&philo->print);
	usleep(philo->args->time_to_eat * 1000);
	return (0);
}

int	nap(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	printf("%lld %i is sleeping\n", current_time(philo->args), philo->id);
	pthread_mutex_unlock(&philo->print);
	usleep(philo->args->time_to_sleep * 1000);
	pthread_mutex_lock(&philo->print);
	printf("%lld %i is thinking\n", current_time(philo->args), philo->id);
	pthread_mutex_unlock(&philo->print);
	return (0);
}

