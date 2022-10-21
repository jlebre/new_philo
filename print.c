/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:28:12 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/20 22:45:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    print(t_philo *philo, char *str)
{
	if (!check_if_dead(philo) || philo->meals == philo->args->number_of_meals)
	{
		pthread_mutex_unlock(&philo->args->print);
		return (0);
	}
	pthread_mutex_lock(&philo->args->check_print);
	if (!philo->args->died)
	{
		printf("%lld %i %s\n", current_time(philo->args), philo->id, str);
	}
	pthread_mutex_unlock(&philo->args->check_print);
	return (1);
}
