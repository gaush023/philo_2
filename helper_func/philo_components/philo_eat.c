/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:17:40 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 17:18:22 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_eat(t_philo_vars *philo_vars)
{
	pthread_mutex_lock(&(philo_vars->vars->forks[philo_vars->ffork]));
	print_behavior("has taken a fork", philo_vars, UNLOCK);
	pthread_mutex_lock(&(philo_vars->vars->forks[philo_vars->sfork]));
	print_behavior("has taken a fork", philo_vars, UNLOCK);
	pthread_mutex_lock(&(philo_vars->vars->meal));
	print_behavior("is eating", philo_vars, UNLOCK);
	philo_vars->last_diet = get_time();
	pthread_mutex_unlock(&(philo_vars->vars->meal));
	oyasumi(philo_vars->vars->time2eat, philo_vars->vars);
	philo_vars->diet_times++;
	pthread_mutex_unlock(&(philo_vars->vars->forks[philo_vars->ffork]));
	pthread_mutex_unlock(&(philo_vars->vars->forks[philo_vars->sfork]));
}
