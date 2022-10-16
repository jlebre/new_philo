/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:59:39 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 17:59:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    destroy_philo(t_args *args)
{
    int i;

    i = 0;
    while (i < args->number_of_philosophers)
    {
        pthread_mutex_destroy(&args->philo[i].fork);
        printf("Mutex Destroy Fork %i\n", (i + 1));
        i++;
    }

    i = 0;
    while (i < args->number_of_philosophers)
    {
        pthread_join(args->philo[i].philo, NULL);
        i++;
    }
    free(args->philo);
	pthread_mutex_destroy(&args->routine);
}