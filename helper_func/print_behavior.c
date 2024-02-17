/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:17:40 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 11:36:58 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_behavior(char *msg, t_philo_vars *philo_vars, int key_status)
{
	unsigned long	timestamp;

	timestamp = get_time() - philo_vars->vars->start_time;
	pthread_mutex_lock(&(philo_vars->vars->print));
	if (!philo_vars->vars->flag && !philo_vars->vars->max_mealstimes)
		printf("%lu %d %s\n", timestamp, philo_vars->pos, msg);
	if (key_status)
		pthread_mutex_unlock(&(philo_vars->vars->print));
}
