/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:27:59 by njung             #+#    #+#             */
/*   Updated: 2025/04/07 15:26:03 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define INT_MAX 2147483647

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;


// Litteralement le dox du philo
typedef struct s_philo
{
    int					id;                  // ID du philosophe
    int					meals_eaten;         // Nombre de repas mangés
    long				last_meal_time;      // Temps du dernier repas
    pthread_t			thread;              // Thread du philosophe
    pthread_mutex_t		*left_fork;          // Fourchette gauche
    pthread_mutex_t		*right_fork;         // Fourchette droite
    t_data				*data;               // Pointeur vers les données partagées
}						t_philo;

typedef struct s_data
{
    int					nb_philo;            // Nombre de philosophes
    int					nb_forks;            // Nombre de fourchettes
    int					time_to_die;         // Temps avant de mourir (ms)
    int					time_to_eat;         // Temps pour manger (ms)
    int					time_to_sleep;       // Temps pour dormir (ms)
    int					nb_meals;            // Nombre de repas avant de terminer (-1 = infini)
    int                 simulation_end;
    long                start_time;
    pthread_mutex_t		*forks;              // Tableau des fourchettes (mutex)
    pthread_mutex_t		print_mutex;         // Mutex pour l'affichage
    pthread_mutex_t     end_mutex;           // Mutex pour voir quand c fini
    pthread_mutex_t     meal_mutex;          // Mutex de la graillance
    t_philo				*philos;             // Tableau des philosophes
}						t_data;

// init.c
void					init_general(int ac, char **av, t_data *data);
void					init_philo(t_data *data);
void					init_mutexes(t_data *data);

// parsing.c
void					ft_usage(void);
void					parsing(int ac, char **av);
int						check_limits(int ac, char **av);
int						check_limits2(int ac, char **av);
int						check_limits3(int ac, char **av);

// parsing2.c
int                     check_letters(int ac, char **av);

// utils.c
int						ft_atoi(const char *str);
void					free_resources(t_data *data);
void                    print_status(t_philo *philo, char *status);
int                     simulation_is_over(t_philo *philo);
void                    set_simulation_end(t_data *data);

// utils2.c
long                    get_current_time(void);
void                    precise_sleep(int milliseconds);
void                    print_death(t_data *data, int i);

// routine.c
void					*philosopher_routine(void *arg);
void                    take_forks(t_philo *philo);
void                    eat(t_philo *philo);
void                    put_down_forks(t_philo *philo);
void                    sleep_philo(t_philo *philo);

// routine2.c
void                    think(t_philo *philo);

// check_philos.c
void                    check_philosopher_status(t_data *data, int i, int *all_ate_enough);
void                    monitor_philosophers(t_data *data);

#endif
