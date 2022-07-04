/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_nd_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:38:15 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/04 02:54:22 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assign_data(char **av, int ac, t_data *data)
{
	data->ph_num = ft_atoi(av[1]);
	data->t2die = ft_atoi(av[2]);
	data->t2eat = ft_atoi(av[3]);
	data->t2sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->eat_num = ft_atoi(av[5]);
	else
		data->eat_num = -1;
	if (data->ph_num > 200 || data->t2die < 60 \
		|| data->t2eat < 60 || data->t2sleep < 60)
		return (1);
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->ph_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->ph_num);
	data->last_meal = malloc(sizeof(long long) * data->ph_num);
	if (!data->philo || !data->forks)
		return (1);
	i = -1;
	while (++i < data->ph_num)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->state = 0;
	}
	if (pthread_mutex_init(&data->full, NULL))
		return (1);
	return (0);
}

int	init_threads(t_data *data)
{
	int	i;

	data->time = get_time();
	if (pthread_mutex_init(&data->mutex, NULL))
		return (1);
	i = -1;
	while (++i < data->ph_num)
	{
		data->last_meal[data->philo->id - 1] = get_time();
		if (pthread_create(&data->philo[i].ph, NULL, &routine, &data->philo[i]))
			return (1);
	}
	check_death(data->philo);
	i = -1;
	while (++i < data->ph_num && !data->state)
		if (pthread_join(data->philo[i].ph, NULL))
			return (1);
	return (0);
}
