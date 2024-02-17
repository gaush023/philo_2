/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:11:24 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/17 13:09:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define UNLOCK 1
# define LOCK 0

enum				e_error
{
	arg_error = -1,
	malloc_error = -2,
	malloc_error2 = -3,
	mutex_error = -4,
	mutex_error2 = -5,
	thread_error = -6,
	close_success = -7
};

typedef struct s_philo_vars
{
	int				diet_times;
	int				pos;
	int				ffork;
	int				sfork;
	unsigned long	last_diet;
	pthread_t		id;
	struct s_vars	*vars;
}					t_philo_vars;

typedef struct s_vars
{
	int				philo_num;
	int				time2die;
	int				time2eat;
	int				time2sleep;
	int				must2eat;
	int				mutex_i;
	int				flag;
	int				max_mealstimes;
	unsigned long	start_time;
	t_philo_vars	*philo_vars;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	print;
}					t_vars;

// libft
int					ft_atoi(char *s);
size_t				ft_strlen(char *s);

// helper_func
int					ft_close(t_vars *vars, enum e_error i);
void				oyasumi(unsigned long time, t_vars *vars);
unsigned long		get_time(void);
int					start_threads(t_vars *vars);
int					philo_allocation(t_vars *vars);
void				philo_eat(t_philo_vars *philo_vars);
void				philo_dead(t_vars *vars, t_philo_vars *philo_vars);
void				*routine(void *params);
void				print_behavior(char *msg, t_philo_vars *philo_vars,
						int key_status);

#endif