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
		if (!eat(philo))
			break ;
		if (!nap(philo))
			break ;
	}
	return (NULL);
}

int	eat(t_philo *philo)
{
	while (check_fork(philo) == 0)
	{
		check_fork(philo);
	}
		pthread_mutex_lock(&philo->args->eat);
		pthread_mutex_lock(&philo->args->print);
		if (!print(philo, "is eating"))
			return (0);
		pthread_mutex_unlock(&philo->args->print);
		while (philo->args->time_to_eat > (get_time() - philo->last_meal))
		{
			if (philo->args->died)
				break ;
		}
		philo->last_meal = current_time(philo->args);
		philo->meals++;
		pthread_mutex_unlock(&philo->args->eat);
		pthread_mutex_unlock(&philo->args->fork[philo->id]);
		if (philo->id == philo->args->number_of_philosophers)
			pthread_mutex_unlock(&philo->args->fork[0]);
		else
			pthread_mutex_unlock(&philo->args->fork[philo->id + 1]);
		return (1);
	return (0);
}

int	nap(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->print);
	if (!print(philo, "is sleeping"))
		return (0);
	pthread_mutex_unlock(&philo->args->print);
	while (philo->args->time_to_sleep > (get_time() - philo->last_nap))
	{
		if (philo->args->died)
				break ;
	}
	philo->last_nap = current_time(philo->args);
	pthread_mutex_lock(&philo->args->print);
	if (!print(philo, "is thinking"))
		return (0);
	pthread_mutex_unlock(&philo->args->print);
	return (1);
}
