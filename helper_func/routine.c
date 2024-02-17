/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:30:34 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 19:14:14 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *params)
{
	t_philo_vars	*philo_vars;
	t_vars			*vars;

	philo_vars = (t_philo_vars *)params;
	vars = philo_vars->vars;
	if (philo_vars->pos % 2 && vars->philo_num > 1)
		oyasumi((vars->time2eat) / 50, vars);
	while (!vars->flag && !vars->max_mealstimes)
	{
		philo_eat(philo_vars);
		print_behavior("is sleeping", philo_vars, UNLOCK);
		oyasumi(vars->time2sleep, vars);
		print_behavior("is thinking", philo_vars, UNLOCK);
	}
	return (NULL);
}
