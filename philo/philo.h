/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:28:18 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/03 22:13:50 by ooumlil          ###   ########.fr       */
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

typedef struct s_philo {
	struct s_data	*data;
	int				id;
	int				is_eating;
	pthread_t		ph;
}	t_philo;

typedef struct s_data{
	int				ph_num;
	int				t2die;
	int				t2eat;
	int				t2sleep;
	int				eat_num;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	pthread_mutex_t	full;
	t_philo			*philo;
	long long		time;
	long long		*last_meal;
	int				state;
}	t_data;

int			ft_atoi(const char *str);
int			check_arguments(char **av);
void		ft_putstr_fd(char *s, int fd);
int			assign_data(char **av, int ac, t_data *data);
int			init_mutex(t_data *data);
int			init_threads(t_data *data);
void		ft_printstatus(t_philo *philo, char *s, int b);
long long	get_time(void);
void		ft_usleep(int time);
void		is_thinking(t_philo *philo);
void		is_asleep(t_philo *philo);
void		is_eating(t_philo *philo);
void		*routine(void *arg);
void		*check_death(t_philo *philo);
void		ft_free(t_data *data);

#endif
