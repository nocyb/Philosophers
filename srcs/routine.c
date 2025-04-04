/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:29:39 by njung             #+#    #+#             */
/*   Updated: 2025/04/04 17:22:15 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (!simulation_is_over(philo))
    {
        take_forks(philo);
        eat(philo);
        put_down_forks(philo);
        sleep_philosopher(philo);
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
