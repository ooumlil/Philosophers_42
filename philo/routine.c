/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:26:37 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/04 05:29:38 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_thinking(t_philo *philo)
{
	ft_printstatus(philo, "is thinking", 1);
}

void	is_asleep(t_philo *philo)
{
	ft_printstatus(philo, "is sleeping", 1);
	ft_usleep(philo->data->t2sleep);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	ft_printstatus(philo, "has taken a fork", 1);
	pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->ph_num]);
	ft_printstatus(philo, "has taken a fork", 1);
	ft_printstatus(philo, "is eating", 1);
	ft_usleep(philo->data->t2sleep);
	philo->data->last_meal[philo->id - 1] = get_time();
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->ph_num]);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		check;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(1000);
	check = 0;
	while (1)
	{
		is_eating(philo);
		check++;
		if (philo->data->eat_num != -1)
		{
			if (check >= philo->data->eat_num)
			{
				philo->data->state = 2;
				break ;
			}
		}
		is_asleep(philo);
		is_thinking(philo);
	}
	return (NULL);
}
