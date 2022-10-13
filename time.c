/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:07:34 by marvin            #+#    #+#             */
/*   Updated: 2022/10/13 01:07:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long    current_time(t_args *args)
{
	struct timeval  current_time;

	gettimeofday(&current_time, NULL);
	return (((current_time.tv_sec - args->start_time.tv_sec) * 1000)
		+ ((current_time.tv_usec - args->start_time.tv_usec) / 1000));
}