/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:06:08 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/06 05:10:39 by ooumlil          ###   ########.fr       */
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

void	kill_children(t_data *data)
{
	int	i;

	i = -1;
	waitpid(-1, NULL, 0);
	while (++i < data->ph_num)
		kill(data->pid[i], SIGKILL);
	free(data->philo->ph);
	free(data->pid);
}
