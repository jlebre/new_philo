/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:20:30 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/19 18:28:51 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork(t_philo *philo)
{
	if (philo->id != (philo->args->number_of_philosophers)
		&& philo->id != (philo->args->number_of_philosophers))
	{
		if (pthread_mutex_lock(&philo->args->fork[philo->id]) == 0)
		{
			if (pthread_mutex_lock(&philo->args->fork[philo->id + 1]) == 0)
			{
				print(philo, "has taken a fork");
				print(philo, "has taken a fork");
				return (1);
			}
			else
				pthread_mutex_unlock(&philo->args->fork[philo->id]);
		}
	}
	else if (philo->id == (philo->args->number_of_philosophers))
	{
		if (pthread_mutex_lock(&philo->args->fork[philo->id]) == 0)
		{
			if (pthread_mutex_lock(&philo->args->fork[0]) == 0)
			{
				print(philo, "has taken a fork");
				print(philo, "has taken a fork");
				return (1);
			}
			else
				pthread_mutex_unlock(&philo->args->fork[philo->id]);
		}
	}
	return (0);
}
