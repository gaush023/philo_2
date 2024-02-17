/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:30:34 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 11:39:43 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	exit_threads(t_vars *vars)
{
	int	i;

	if (vars->philo_num == 1)
		pthread_detach(vars->philo_vars[0].id);
	else
	{
		i = 0;
		while (i < vars->philo_num)
		{
			pthread_join(vars->philo_vars[i].id, NULL);
			i++;
		}
	}
	ft_close(vars, close_success);
}

int	start_threads(t_vars *vars)
{
	int	i;

	i = 0;
	vars->start_time = get_time();
	while (i < vars->philo_num)
	{
		vars->philo_vars[i].last_diet = get_time();
		if (pthread_create(&(vars->philo_vars[i].id), NULL, routine,
				&(vars->philo_vars[i])))
			return (ft_close(vars, thread_error));
		i++;
	}
	philo_dead(vars, vars->philo_vars);
	pthread_mutex_unlock(&(vars->print));
	exit_threads(vars);
	return (0);
}
