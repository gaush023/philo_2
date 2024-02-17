/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 03:09:38 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 16:55:45 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	byebye_mutex(t_vars *vars, enum e_error i)
{
	while (vars->mutex_i > 0)
	{
		--vars->mutex_i;
		pthread_mutex_destroy(&(vars->forks[vars->mutex_i]));
	}
	if (i <= mutex_error2)
		pthread_mutex_destroy(&(vars->meal));
	if (i < mutex_error2)
		pthread_mutex_destroy(&(vars->print));
}

static void	delete_malloc(t_vars *vars, enum e_error i)
{
	if (i < malloc_error)
		free(vars->philo_vars);
	if (i < malloc_error2)
		free(vars->forks);
}

static void	ft_no_leaks(t_vars *vars, enum e_error i)
{
	delete_malloc(vars, i);
	if (malloc_error < i && i >= malloc_error2)
		byebye_mutex(vars, i);
}

int	ft_close(t_vars *vars, enum e_error i)
{
	if (i == arg_error)
		write(2, "Error: wrong argument1\n", 23);
	else if (malloc_error < i && i >= malloc_error2)
	{
		write(2, "Error: malloc failed3\n", 21);
		ft_no_leaks(vars, i);
	}
	else if (i <= mutex_error && i >= mutex_error2)
	{
		write(2, "Error: mutex failed", 20);
		ft_no_leaks(vars, i);
	}
	else if (i == thread_error)
	{
		write(2, "Error: thread failed\n", 21);
		ft_no_leaks(vars, i);
	}
	else if (i == close_success)
	{
		ft_no_leaks(vars, i);
		return (0);
	}
	return (-1);
}
