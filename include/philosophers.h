/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:27:59 by njung             #+#    #+#             */
/*   Updated: 2025/04/14 11:38:01 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					nb_forks;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_meals;
	int					simulation_end;
	long				start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		end_mutex;
	pthread_mutex_t		meal_mutex;
	t_philo				*philos;
}						t_data;

// init.c
int						init_general(int ac, char **av, t_data *data);
void					init_philo(t_data *data);
void					init_mutexes(t_data *data);

// parsing.c
void					ft_usage(void);
int						parsing(int ac, char **av);
int						check_limits(int ac, char **av);
int						check_limits2(int ac, char **av);
int						check_limits3(int ac, char **av);

// parsing2.c
int						check_letters(int ac, char **av);

// utils.c
int						ft_atoi(const char *str);
void					free_resources(t_data *data);
int						simulation_is_over(t_philo *philo);
void					set_simulation_end(t_data *data);

// utils2.c
long					get_current_time(void);
void					precise_sleep(int milliseconds);
void					print_death(t_data *data, int i);
void					print_status(t_philo *philo, char *status);

// routine.c
void					*philosopher_routine(void *arg);
void					take_forks(t_philo *philo);
void					eat(t_philo *philo);
void					put_down_forks(t_philo *philo);
void					sleep_philo(t_philo *philo);

// routine2.c
void					think(t_philo *philo);
void					*one_philosopher_routine(void *arg);

// check_philos.c
void					check_philosopher_status(t_data *data, int i,
							int *all_ate_enough);
void					monitor_philosophers(t_data *data);
void					join_threads(t_data *data);

#endif
