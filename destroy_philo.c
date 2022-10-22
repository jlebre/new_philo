/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:19 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:19 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->number_of_philosophers)
	{
		if (pthread_join(philo[i].philo, NULL))
			ft_error("Failed to join threads!\n");
		i++;
	}
	kill_everything(philo);
}

void	kill_everything(t_philo *philo)
{
	int	i;
	int	nb;

	i = 0;
	nb = philo->args->number_of_philosophers;
	while (i < nb)
	{
		pthread_mutex_destroy(&philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(&philo->args->mutex);
	free(philo);
}
