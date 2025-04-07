/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:42:21 by njung             #+#    #+#             */
/*   Updated: 2025/04/07 13:42:43 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void think(t_philo *philo)
{
    print_status(philo, "is thinking");
    if (philo->data->nb_philo % 2 != 0)
        precise_sleep(philo->data->time_to_eat / 2);
}
