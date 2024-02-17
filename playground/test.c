#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t	lock;

int				counter = 0;

void	*mythreadfun(void *arg)
{
	arg = NULL;
	pthread_mutex_lock(&lock);
	counter++;
	printf("Thread id: %d\n", (int)pthread_self());
	printf("Counter value: %d\n", counter);
	pthread_mutex_unlock(&lock);
	return (NULL);
}

int	main(void)
{
	pthread_t	id[10];
	int			i;

	printf("Before thread\n");
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("Mutex init failed\n");
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_create(&id[i], NULL, mythreadfun, NULL) != 0)
		{
			printf("Thread creation failed\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(id[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&lock);
	printf("After thread\n");
	return (0);
}
