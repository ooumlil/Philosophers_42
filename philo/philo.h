/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:28:18 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/28 06:39:23 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_data{
	int				ph_num;
	int				t2die;
	int				t2eat;
	int				t2sleep;
	int				eat_num;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo {
	t_data	*data;
	int		last_eat;
	int		id;
	int		state;
}	t_philo;

int		ft_atoi(const char *str);
int		check_arguments(char **av);
void	ft_putstr_fd(char *s, int fd);
int		assign_data(char **av, int ac, t_data *data);
int		ft_mutex_init(t_data *data, t_philo *philo);

#endif
