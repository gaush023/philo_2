#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int				i;
	int				flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	print;

	i = 0;
	flag = 5;
	forks = malloc(flag * sizeof(pthread_mutex_t));
	if (!forks)
		return (printf("Malloc failed\n"));
	while (i < flag)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			break ;
		i++;
	}
	if (i != flag)
		return (printf("Error\n"));
	if (pthread_mutex_init(&meal, NULL))
		return (printf("Error2\n"));
	if (pthread_mutex_init(&print, NULL))
		return (0);
}
