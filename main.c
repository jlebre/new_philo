/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:50:06 by marvin            #+#    #+#             */
/*   Updated: 2022/10/01 16:50:06 by marvin           ###   ########.fr       */
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
	//sleep(10);
	destroy_philo(&args);
	green("Ready!\n");
	return (0);
}
	
//while (died(&args) != 0)
