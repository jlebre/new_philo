/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:28:12 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/19 18:15:09 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    print(t_philo *philo, char *str)
{
    //pthread_mutex_lock(&philo->print);
    if (!check_if_dead(philo) || philo->meals == philo->args->number_of_meals)
        return (0);
    printf("%lld %i %s\n", current_time(philo->args), philo->id, str);
   // pthread_mutex_unlock(&philo->print);
    return (1);
}