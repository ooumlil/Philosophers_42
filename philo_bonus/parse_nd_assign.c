/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nd_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:26:43 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/05 05:00:37 by ooumlil          ###   ########.fr       */
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

void	arguments_check(char **av, int ac)
{
	int	i;

	if (ac != 5 && ac != 6)
		exit(1);
	i = 0;
	while (av[++i])
		if (ft_atoi(av[i]) <= 0)
			exit(1);
}

void	assign_data_b(char **av, int ac, t_data *data)
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
		exit(1);
}

void	kill_children(t_data *data, int *pid)
{
	int	i;

	i = -1;
	waitpid(-1, NULL, 0);
	while (++i < data->ph_num)
		kill(pid[i], SIGKILL);
	free(data->philo->ph);
	free(pid);
}
