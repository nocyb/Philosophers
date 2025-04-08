/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:29:39 by njung             #+#    #+#             */
/*   Updated: 2025/04/08 13:51:24 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->data->nb_philo == 1){
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
        precise_sleep(philo->data->time_to_die);
        return (NULL);
    }

    if (philo->id % 2 == 0)
        precise_sleep(philo->data->time_to_eat / 2);

    while (!simulation_is_over(philo))
    {
        take_forks(philo);
        eat(philo);
        put_down_forks(philo);
        sleep_philo(philo);
        think(philo);
    }
    return (NULL);
}

void take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
       pthread_mutex_lock(philo->right_fork);
       print_status(philo, "has taken a fork");
       pthread_mutex_lock(philo->left_fork);
       print_status(philo, "has taken a fork");
    }
    else
    {
       pthread_mutex_lock(philo->left_fork);
       print_status(philo, "has taken a fork");
       pthread_mutex_lock(philo->right_fork);
       print_status(philo, "has taken a fork"); 
    }
}
void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->meal_mutex);
    philo->last_meal_time = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->meal_mutex);
    print_status(philo, "is eating");
    precise_sleep(philo->data->time_to_eat);
}
void put_down_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
    }
    else
    {
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
    }
}
void sleep_philo(t_philo *philo)
{
    print_status(philo, "is sleeping");
    precise_sleep(philo->data->time_to_sleep);
}
