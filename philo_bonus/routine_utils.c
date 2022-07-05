/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:06:08 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/05 01:08:45 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_printstatus(t_philo *philo, char *s, int b)
{
	if (s)
	{
		sem_wait(philo->print);
		printf("%lld %d %s\n", get_time() - philo->data->time, philo->id, s);
	}
	if (b)
		sem_post(philo->print);
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