/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:14:01 by njung             #+#    #+#             */
/*   Updated: 2025/04/07 19:44:25 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void check_philosopher_status(t_data *data, int i, int *all_ate_enough)
{
    long time_since_last_meal;
    
    pthread_mutex_lock(&data->meal_mutex);
    time_since_last_meal = get_current_time() - data->philos[i].last_meal_time;
    if (time_since_last_meal > data->time_to_die)
    {
        pthread_mutex_unlock(&data->meal_mutex);
        set_simulation_end(data);
        print_death(data, i);
        *all_ate_enough = -1;
        return;
    }
    if (data->nb_meals != -1 && data->philos[i].meals_eaten < data->nb_meals)
        *all_ate_enough = 0;
    pthread_mutex_unlock(&data->meal_mutex);
}

void monitor_philosophers(t_data *data)
{
    int i;
    int all_ate_enough;
    
    while (1)
    {
        i = -1;
        all_ate_enough = 1;
        while (++i < data->nb_philo)
        {
            check_philosopher_status(data, i, &all_ate_enough);
            if (all_ate_enough == -1)
                return;
        }
        if (data->nb_meals != -1 && all_ate_enough)
        {
            set_simulation_end(data);
            return;
        }
        usleep(1000);
    }
}