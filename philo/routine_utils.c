/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 04:15:29 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/04 00:13:47 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printstatus(t_philo *philo, char *s, int b)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (s)
		printf("%lld %d %s\n", get_time() - philo->data->time, philo->id, s);
	if (b)
		pthread_mutex_unlock(&philo->data->mutex);
}

void	ft_usleep(int time)
{
	long long	t;

	t = get_time();
	while (get_time() - t < time)
		usleep(1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*check_death(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->data->ph_num)
		{
			if (get_time() - philo->data->last_meal[philo->id - 1] \
			>= philo->data->t2die)
			{
				if (philo->data->state != 2)
					ft_printstatus(&philo->data->philo[i], "died", 0);
				philo->data->state = 1;
				break ;
			}
			i++;
		}
		if (philo->data->state == 1)
			break ;
	}
	return (NULL);
}

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->mutex);
	while (++i < data->ph_num)
		pthread_mutex_destroy(&data->forks[i]);
	return ;
}
