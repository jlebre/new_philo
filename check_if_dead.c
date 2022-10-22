/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:28 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/22 16:03:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		pthread_mutex_lock(&philo->args->mutex);
		while (i < philo->args->number_of_philosophers && philo->args->died != 1)
		{
			if (get_time() - philo->last_meal >= philo->args->time_to_die)
			{
				printf("%lld %i died\n", current_time(philo->args), philo->id);
				philo->args->died = 1;
				pthread_mutex_unlock(&philo->args->mutex);
				return (0);
			}
			if (!all_ate(philo))
				return (0);
			if (!only_one_philosopher(philo))
				return (0);
			i++;
		}
		pthread_mutex_unlock(&philo->args->mutex);
		usleep(1960);
	}
}

int	all_ate(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->args->number_of_meals != -1
		&& i < philo->args->number_of_philosophers
		&& philo[i].meals >= philo->args->number_of_meals)
		i++;
	if (i == philo->args->number_of_philosophers)
	{
		philo->args->died = 1;
		pthread_mutex_unlock(&philo->args->mutex);
		return (0);
	}
	return (1);
}

int	only_one_philosopher(t_philo *philo)
{
	if (philo->args->number_of_philosophers == 1)
	{
		usleep(philo->args->time_to_die * 1000);
		printf("%lld %d died\n", current_time(philo->args), philo->id);
		philo->args->died = 1;
		pthread_mutex_unlock(&philo->args->mutex);
		return (0);
	}
	return (1);
}