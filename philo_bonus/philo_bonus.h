/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:17:14 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/05 04:59:18 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>

typedef struct philo
{
	sem_t			*sem;
	sem_t			*print;
	int				is_eating;
	int				is_dead;
	struct s_data	*data;
	long long		last_meal;
	int				id;
	pthread_t		ph;
}	t_philo;

typedef struct s_data{
	t_philo			*philo;
	int				ph_num;
	int				t2die;
	int				t2eat;
	int				t2sleep;
	int				eat_num;
	int				full;
	long long		time;
	int				state;
}	t_data;

int			ft_atoi(const char *str);
void		arguments_check(char **av, int ac);
void		assign_data_b(char **av, int ac, t_data *data);
int			*create_children(t_data *data);
void		is_asleep(t_philo *philo);
void		is_eating(t_philo *philo);
void		*routine(void *arg);
void		print_behavior(t_philo *philo);
void		ft_printstatus(t_philo *philo, char *s, int b);
void		ft_usleep(int time);
long long	get_time(void);
void		kill_children(t_data *data, int *pid);

#endif