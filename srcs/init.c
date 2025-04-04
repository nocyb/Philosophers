/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:53:27 by njung             #+#    #+#             */
/*   Updated: 2025/04/04 15:36:02 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_mutexes(t_data *data)
{
    int	i;

    i = 0;
    while (i < data->nb_philo)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->print_mutex, NULL);
    pthread_mutex_init(&data->end_mutex, NULL);
    pthread_mutex_init(&data->meal_mutex, NULL);
}

void	init_general(int ac, char **av, t_data *data)
{
    data->nb_philo = ft_atoi(av[1]);
    data->nb_forks = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->nb_meals = ft_atoi(av[5]);
    else
        data->nb_meals = -1;
    data->simulation_end = 0;
    data->start_time = 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
    if (!data->forks)
    {
        write(1, "Memory allocation failed for forks\n", 35);
        exit(1);
    }
    data->philos = malloc(sizeof(t_philo) * data->nb_philo);
    if (!data->philos)
    {
        write(1, "Memory allocation failed for philosophers\n", 42);
        free(data->forks);
        exit(1);
    }
    init_mutexes(data);
}

void	init_philo(t_data *data)
{
    int	i;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    data->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;

    i = 0;
    while (i < data->nb_philo)
    {
        data->philos[i].id = i + 1;
        data->philos[i].meals_eaten = 0;
        data->philos[i].last_meal_time = data->start_time;
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
        data->philos[i].data = data;
        pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
            &data->philos[i]);
        i++;
    }
}
