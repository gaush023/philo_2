/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:11:44 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 10:46:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	ini_ph(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->philo_num)
	{
		vars->philo_vars[i].diet_times = 0;
		vars->philo_vars[i].pos = i + 1;
		vars->philo_vars[i].ffork = i;
		vars->philo_vars[i].sfork = (i + 1) % vars->philo_num;
		vars->philo_vars[i].vars = vars;
		i++;
	}
}

static int	ini_mu(t_vars *vars)
{
	vars->mutex_i = 0;
	while (vars->mutex_i < vars->philo_num)
	{
		if (pthread_mutex_init(&(vars->forks[vars->mutex_i]), NULL))
			break ;
		vars->mutex_i++;
	}
	if (vars->mutex_i != vars->philo_num)
		return (ft_close(vars, mutex_error));
	if (pthread_mutex_init(&vars->meal, NULL))
		return (ft_close(vars, mutex_error));
	if (pthread_mutex_init(&vars->print, NULL))
		return (ft_close(vars, mutex_error2));
	ini_ph(vars);
	return (start_threads(vars));
}

int	philo_allocation(t_vars *vars)
{
	vars->philo_vars = malloc(sizeof(t_philo_vars) * vars->philo_num);
	if (!vars->philo_vars)
		return (ft_close(NULL, malloc_error));
	vars->forks = malloc(sizeof(t_philo_vars) * vars->philo_num);
	if (!vars->forks)
		return (ft_close(vars, malloc_error2));
	return (ini_mu(vars));
}
