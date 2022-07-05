/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:16:36 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/05 05:01:08 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		*pid;

	arguments_check(av, ac);
	assign_data_b(av, ac, &data);
	sem_unlink("sem");
	sem_unlink("print");
	pid = create_children(&data);
	sem_close(data.philo->print);
	sem_close(data.philo->sem);
	kill_children(&data, pid);
}
