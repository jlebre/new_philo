/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:20:30 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:31:11 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    check_fork(t_args *args)
{
    if (args->philo->id)
    
    if (i != (args->number_of_philosophers) && i < (args->number_of_philosophers))
        if ([i] && [i + 1])
        {
            pthread_mutex_lock(&args->philo[i].fork);
            pthread_mutex_lock(&args->philo[i + 1].fork);
        }
    else if (i == (args->number_of_philosophers))
        if ([i] && [0])
        {
            pthread_mutex_lock(&args->philo[i].fork);
            pthread_mutex_lock(&args->philo[0].fork);
        }
}
