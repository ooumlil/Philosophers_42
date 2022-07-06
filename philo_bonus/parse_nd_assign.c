/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nd_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:26:43 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/06 05:15:29 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] && (str[i] > '9' || str[i] < '0'))
		return (-1);
	return (sign * result);
}

void	check_nd_assign(char **av, int ac, t_data *data)
{
	int	i;

	if (ac != 5 && ac != 6)
		exit(1);
	i = 0;
	while (av[++i])
		if (ft_atoi(av[i]) <= 0)
			exit(1);
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
		exit(1);
}

void	fill_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->ph_num);
	data->time = get_time();
	while (i < data->ph_num)
	{
		data->philo->last_meal = data->time;
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->state = 0;
		data->full = 0;
		i++;
	}
}

void	init_sems(t_data *data)
{
	sem_unlink("semap");
	sem_unlink("print");
	create_children(data);
	sem_close(data->philo->semap);
	sem_close(data->philo->print);
	kill_children(data);
}
