/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:28:13 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/28 06:54:05 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thread_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->ph_num)
	{
		philo->id = i + 1;
		philo->state = 1; 
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (ac != 5 && ac != 6 && check_arguments(av))
		return (1);
	if (assign_data(av, ac, &data))
		return (1);
	philo = NULL;
	if (ft_mutex_init(&data, philo) && ft_thread_init(philo))
		return (1);
	return (0);
}
