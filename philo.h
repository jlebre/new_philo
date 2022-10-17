/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:33:32 by jlebre            #+#    #+#             */
/*   Updated: 2022/10/17 13:33:32 by jlebre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
//# include <time.h>
# include <sys/time.h> 
# include <pthread.h>

# define INT_MAX    2147483647
# define INT_MIN    -2147483648

typedef struct s_philo
{
	int 			id;
	int				meals;
	long long		last_meal;
	pthread_mutex_t fork;
	pthread_mutex_t routine;
	pthread_t		philo;
	struct s_args	*args;
}	t_philo;

typedef struct s_args
{
	int				died;
	int				number_of_philosophers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	int				number_of_meals;
}   t_args;

//CHECK
void    			check(char **argv);
void    			check_all_int(char **argv);
void    			check_limits(char **argv);

//START ARGS
void				start_args(int argc, char **argv, t_args *args);
t_philo     		*start_philo(t_args  *args);

//PHILO
void    			create_philo(t_args *args);
int	    			destroy_philo(t_philo *philo, t_args *args);

//ROUTINE
void				*routine(void *arg);

//TIME
long long			get_time();
long long  			current_time(t_args *args);

//UTILS
void    			ft_error(char	*str);
int					ft_isdigit(int i);
int					ft_atoi(const char *str);
long long			ft_atol(const char *str);

//COLORS
int					red(char *str);
int					green(char *str);
int					yellow(char *str);

#endif