/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:28 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/19 18:27:01 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_philo *philo)
{
	if ((get_time() - philo->last_meal) > philo->args->time_to_die)
	{
		pthread_mutex_lock(&philo->args->died);
		philo->args->died = 1;
		printf("%lld %i died\n", current_time(philo->args), philo->id);
		pthread_mutex_unlock(&philo->args->died);
		return (0);
	}
	//pthread_mutex_unlock(&philo->died);
	return (1);
}
