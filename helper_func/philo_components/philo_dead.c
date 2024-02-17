/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:44:14 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 13:05:21 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_dead(t_vars *vars, t_philo_vars *philo_vars)
{
	int	i;

	i = 0;
	while (vars->max_mealstimes != 1)
	{
		while (i < vars->philo_num && vars->flag != 1)
		{
			pthread_mutex_lock(&(vars->meal));
			if ((int)(get_time() - philo_vars[i].last_diet) >= vars->time2die)
			{
				print_behavior("died", &philo_vars[i], LOCK);
				vars->flag = 1;
			}
			pthread_mutex_unlock(&(vars->meal));
			i++;
		}
		if (vars->flag)
			break ;
		i = 0;
		while (vars->must2eat != -1 && i < vars->philo_num
			&& philo_vars[i].diet_times >= vars->must2eat)
			i++;
		vars->max_mealstimes = (i == vars->philo_num);
	}
}
