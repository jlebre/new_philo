/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:39:40 by marvin            #+#    #+#             */
/*   Updated: 2022/10/11 17:39:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    create_philo(t_args *args)
{
    int i;

    i = 1;
    args->philo = malloc(sizeof(t_philo) * args->number_of_philosophers);
    if (!args->philo)
        return ;
    while (i < args->number_of_philosophers + 1)
    {
        pthread_mutex_init(&args->philo[i].fork, NULL);
        printf("Mutex Init Fork %i\n", i);
        i++;
    }
    i = 1;
    while (i < args->number_of_philosophers + 1)
    {
        args->philo[i].id = i;
        pthread_create(&args->philo[i].philo, NULL, &routine, &args->philo[i]);
        printf("%i created!\n", i);
        //usleep(1000);
        i++;
    }
    pthread_mutex_init(&args->eat, NULL);
}