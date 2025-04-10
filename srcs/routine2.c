/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:42:21 by njung             #+#    #+#             */
/*   Updated: 2025/04/10 14:35:02 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
	if (philo->data->nb_philo % 2 != 0)
		precise_sleep(philo->data->time_to_eat / 2);
}

void	*one_philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	precise_sleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}
