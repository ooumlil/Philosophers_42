/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_and_mutex_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 04:38:15 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/28 04:38:42 by ooumlil          ###   ########.fr       */
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
		data->eat_num = 0;
	if (data->ph_num > 200 || data->t2die < 60 \
		|| data->t2eat < 60 || data->t2sleep < 60)
		return (1);
	return (0);
}

int	ft_mutex_init(t_data *data, t_philo *philo)
{
	int	i;

	philo = malloc(sizeof(t_philo) * data->ph_num);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->ph_num);
	if (!philo || !data->forks)
		return (1);
	i = 0;
	while (i < data->ph_num)
		pthread_mutex_init(&data->forks[i], NULL);
	return (0);
}
