/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:48:49 by sagemura          #+#    #+#             */
/*   Updated: 2024/02/15 19:23:57 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static long	ft_atoi_helper(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
		return (-1);
	return (i);
}

static long	ft_length(char *s, int i)
{
	while (s[i] != '\0')
		i++;
	while (s[i - 1] == ' ')
		i--;
	return (i);
}

int	ft_atoi(char *s)
{
	long	i;
	int		flag;
	long	length;
	long	res;

	i = ft_atoi_helper(s);
	if (i == -1)
		return (-1);
	flag = i;
	length = ft_length(s, i);
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	if (i != flag && length == i)
		return (res);
	else
		return (-1);
}

// int	main(int ar, char **av)
// {
// 	int i;

// 	i = 1;
// 	if (ar == 0)
// 		return (-1);
// 	while (i < ar)
// 	{
// 		printf("%d\n%s\n", ft_atoi(av[i]), av[i]);
// 		i++;
// 	}
// 	i = 1;
// 	while (i < ar)
// 	{
// 		if (ft_atoi(av[i]) == -1)
// 			return (printf("%d\n%s\n", ft_atoi(av[i]), av[i]));
// 		i++;
// 	}
// 	return (0);
// }