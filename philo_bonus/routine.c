/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:57:08 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/06 05:17:47 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	is_asleep(t_philo *philo)
{
	ft_printstatus(philo, "is sleeping", 1);
	ft_usleep(philo->data->t2sleep);
}

void	is_eating(t_philo *philo)
{
	sem_wait(philo->semap);
	ft_printstatus(philo, "has taken a fork", 1);
	philo->last_meal = get_time() - philo->data->time;
	sem_wait(philo->semap);
	ft_printstatus(philo, "has taken a fork", 1);
	ft_printstatus(philo, "is eating", 1);
	philo->last_meal = get_time() - philo->data->time;
	ft_usleep(philo->data->t2eat);
	sem_post(philo->semap);
	sem_post(philo->semap);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!(philo->id % 2))
		usleep(1000);
	while (1)
	{
		is_eating(philo);
		philo->is_eating += 1;
		is_asleep(philo);
		ft_printstatus(philo, "is thinking", 1);
	}
	return (NULL);
}

void	print_behavior(t_philo *philo)
{
	philo->semap = sem_open("semap", O_CREAT, 0660, philo->data->ph_num);
	philo->print = sem_open("print", O_CREAT, 0660, 1);
	if (philo->semap == SEM_FAILED || philo->print == SEM_FAILED)
		return (free(philo->ph), exit(0));
	pthread_create(&philo->ph, NULL, routine, philo);
	pthread_detach(philo->ph);
	while (1)
	{
		if (get_time() - philo->last_meal - philo->data->time \
		>= philo->data->t2die)
		{
			ft_printstatus(philo, "died", 0);
			exit(1);
		}
		if (philo->data->eat_num != -1)
			if (philo->is_eating > philo->data->eat_num)
				exit(0);
		usleep(50);
	}
	return ;
}

void	create_children(t_data *data)
{
	int	i;
	int	pid;

	data->pid = (int *)malloc(sizeof(int) * data->ph_num);
	i = -1;
	while (++i < data->ph_num)
	{
		pid = fork();
		if (pid == 0)
		{
			print_behavior(&data->philo[i]);
			exit(0);
		}
		else
			data->pid[i] = pid;
	}
}
