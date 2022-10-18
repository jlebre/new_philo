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
		if (check_if_dead(philo))
			if (eat(philo))
				break ;
		if (check_if_dead(philo))
			if (nap(philo))
				break;
	}
	return (NULL);
}

int	eat(t_philo *philo)
{
	if (check_if_dead(philo))
	{
		if (check_fork(philo))
		{
			pthread_mutex_lock(&philo->print);
			printf("%lld %i is eating\n", current_time(philo->args), philo->id);
			pthread_mutex_unlock(&philo->print);
			philo->last_meal = current_time(philo->args);
			usleep(philo->args->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->fork[philo->id]);
			if (philo->id == philo->args->number_of_philosophers)
				pthread_mutex_unlock(&philo->fork[0]);
			else
				pthread_mutex_unlock(&philo->fork[philo->id + 1]);
		}
		return (0);
	}
	return (1);
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

