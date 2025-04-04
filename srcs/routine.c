/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:29:39 by njung             #+#    #+#             */
/*   Updated: 2025/04/04 14:26:31 by njung            ###   ########.fr       */
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
    return NULL;
}
