#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct ThreadData
{
	pthread_t		id[10];
	int				*counter;
	int				stop;
	pthread_mutex_t	lock;
}					ThreadData;

void	*mythreadfun(void *arg)
{
	ThreadData	*data;

	data = (ThreadData *)arg;
	while (data->stop == 0)
	{
		pthread_mutex_lock(&data->lock);
		*(data->counter) += 1;
		printf("Thread id: %lu\n", (unsigned long)pthread_self());
		printf("Counter value: %d\n", *(data->counter));
		pthread_mutex_unlock(&data->lock);
	}
	if (data->stop == 1)
		printf("stopping thread\n");
	return (NULL);
}

int	main(void)
{
	ThreadData	data;
	int			i;

	i = 0;
	data.counter = (int *)malloc(sizeof(int));
	*data.counter = 0;
	data.stop = 0;
	pthread_mutex_init(&data.lock, NULL);
	while (i < 10)
	{
		if (pthread_create(&data.id[i], NULL, mythreadfun, &data) != 0)
		{
			printf("Thread creation failed\n");
			return (1);
		}
		i++;
	}
	sleep(1);
	data.stop = 1;
	i = 0;
	while (i < 10)
	{
		pthread_join(data.id[i], NULL);
		i++;
	}
	free(data.counter);
	pthread_mutex_destroy(&data.lock);
	printf("After thread\n");
	return (0);
}
