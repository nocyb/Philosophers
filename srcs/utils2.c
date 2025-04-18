/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:36:14 by njung             #+#    #+#             */
/*   Updated: 2025/04/10 16:12:00 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	precise_sleep(int milliseconds)
{
	long	start_time;
	long	end_time;

	start_time = get_current_time();
	end_time = start_time + milliseconds;
	while (get_current_time() < end_time)
		usleep(100);
}

void	print_death(t_data *data, int i)
{
	long	timestamp;

	pthread_mutex_lock(&data->print_mutex);
	timestamp = get_current_time() - data->start_time;
	printf("%ld %d died\n", timestamp, data->philos[i].id);
	pthread_mutex_unlock(&data->print_mutex);
}

void	print_status(t_philo *philo, char *status)
{
	long	timestamp;

	if (simulation_is_over(philo))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!simulation_is_over(philo))
	{
		timestamp = get_current_time() - philo->data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}
