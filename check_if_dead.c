/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:28 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/18 16:07:07 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_philo *philo)
{
	if ((current_time(philo->args) - philo->last_meal) > philo->args->time_to_die)
	{
		pthread_mutex_lock(&philo->print);
		printf("%lld %i died\n", current_time(philo->args), philo->id);
		pthread_mutex_unlock(&philo->print);
		destroy_philo(philo, philo->args);
	}
	return (1);
}
