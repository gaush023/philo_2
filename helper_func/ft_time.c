/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:30:34 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 17:20:54 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void	oyasumi(unsigned long time, t_vars *vars)
{
	unsigned long	start;

	start = get_time();
	while (!vars->flag)
	{
		if (get_time() - start >= time)
			break ;
		usleep(vars->philo_num);
	}
}
