/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:24 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:24 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_args  args;

	if (argc < 2)
		ft_error("No Arguments!\n");
	check(argv);
	start_args(argc, argv, &args);
	create_philo(&args);
	green("Ready!\n");
	return (0);
}
	
//while (died(&args) != 0)
/*
	printf("START_TIME: %lld\n", args.llstart_time);
	printf("NB: %i\n", args.number_of_philosophers);
	printf("TTD: %lld\n", args.time_to_die);
	printf("TTE: %lld\n", args.time_to_eat);
	printf("TTS: %lld\n", args.time_to_sleep);
*/