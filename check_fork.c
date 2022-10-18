/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:20:30 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/18 16:05:22 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork(t_philo *philo)
{
	if (philo->id != (philo->args->number_of_philosophers)
		&& philo->id != (philo->args->number_of_philosophers))
	{
		if (pthread_mutex_lock(&philo->fork[philo->id]) == 0)
		{
			if (pthread_mutex_lock(&philo->fork[philo->id + 1]) == 0)
				return (1);
			else
				pthread_mutex_unlock(&philo->fork[philo->id]);
		}
	}
	else if (philo->id == (philo->args->number_of_philosophers))
	{
		if (pthread_mutex_lock(&philo->fork[philo->id]) == 0)
		{
			if (pthread_mutex_lock(&philo->fork[0]) == 0)
				return (1);
			else
				pthread_mutex_unlock(&philo->fork[philo->id]);
		}
	}
	return (0);
}
