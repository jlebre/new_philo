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

long long get_time(t_args *args)
{
	struct timeval	tv;
	long long		sec;
	long long		usec;

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec - args->start_time.tv_sec;
	usec = tv.tv_usec - args->start_time.tv_usec;
	return ((usec / 1000) + (sec * 1000));
}
/*
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (long long)1000) + (time.tv_usec / 1000));
}
*/
long long	current_time(t_args *args)
{
	//printf("GT: %lld\n", get_time(args));
	//printf("ST: %lld\n", args->llstart_time);
	return (get_time(args) - args->llstart_time);
}
