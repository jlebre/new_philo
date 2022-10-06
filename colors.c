/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:52:49 by marvin            #+#    #+#             */
/*   Updated: 2022/10/06 17:52:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	black(char *str)
{
	return (printf("\033[0;30m%s\033[0m", str));
}

int	red(char *str)
{
	return (printf("\033[0;31m%s\033[0m", str));
}

int	green(char *str)
{
	return (printf("\033[0;32m%s\033[0m", str));
}

int	yellow(char *str)
{
	return (printf("\033[0;33m%s\033[0m", str));
}

int	blue(char *str)
{
	return (printf("\033[0;34m%s\033[0m", str));
}

int	purple(char *str)
{
	return (printf("\033[0;35m%s\033[0m", str));
}

int	cyan(char *str)
{
	return (printf("\033[0;36m%s\033[0m", str));
}

int	white(char *str)
{
	return (printf("\033[0;37m%s\033[0m", str));
}

//BOLD

int	bold_black(char *str)
{
	return (printf("\033[1;30m%s\033[0m", str));
}

int	bold_red(char *str)
{
	return (printf("\033[1;31m%s\033[0m", str));
}

int	bold_green(char *str)
{
	return (printf("\033[1;32m%s\033[0m", str));
}

int	bold_yellow(char *str)
{
	return (printf("\033[1;33m%s\033[0m", str));
}

int	bold_blue(char *str)
{
	return (printf("\033[1;34m%s\033[0m", str));
}

int	bold_purple(char *str)
{
	return (printf("\033[1;35m%s\033[0m", str));
}

int	bold_cyan(char *str)
{
	return (printf("\033[1;36m%s\033[0m", str));
}

int	bold_white(char *str)
{
	return (printf("\033[1;37m%s\033[0m", str));
}

//ADD TO .h

//Normal Colors
int	black(char *str);
int	red(char *str);
int	green(char *str);
int	yellow(char *str);
int	blue(char *str);
int	purple(char *str);
int	cyan(char *str);
int	white(char *str);
//Bold
int	bold_black(char *str);
int	bold_red(char *str);
int	bold_green(char *str);
int	bold_yellow(char *str);
int	bold_blue(char *str);
int	bold_purple(char *str);
int	bold_cyan(char *str);
int	bold_white(char *str);
