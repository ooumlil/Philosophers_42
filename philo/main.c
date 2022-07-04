/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:28:13 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/03 04:14:08 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if ((ac != 5 && ac != 6) || check_arguments(av))
		return (1);
	if (assign_data(av, ac, &data))
		return (1);
	if (init_mutex(&data))
		return (1);
	if (init_threads(&data))
		return (1);
	ft_free(&data);
	return (0);
}
