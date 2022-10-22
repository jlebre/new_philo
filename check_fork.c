/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:20:30 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/22 16:17:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	pthread_mutex_lock(&philo->right_fork);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
		return (0);
	}
	return (1);
}

int	check_fork_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->right_fork);
	}
	pthread_mutex_lock(philo->left_fork);
	if (!print(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
		return (0);
	}
	return (1);
}
