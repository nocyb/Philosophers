/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:38:04 by njung             #+#    #+#             */
/*   Updated: 2025/04/10 16:12:13 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_overflow(int sign)
{
	if (sign == 1)
		return (INT_MAX);
	else
		return (-INT_MAX - 1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		s;

	i = 0;
	res = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res * s > INT_MAX || res * s < -INT_MAX - 1)
			return (handle_overflow(s));
		i++;
	}
	return ((int)(res * s));
}

void	free_resources(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->end_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

int	simulation_is_over(t_philo *philo)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->data->end_mutex);
	result = philo->data->simulation_end;
	pthread_mutex_unlock(&philo->data->end_mutex);
	return (result);
}

void	set_simulation_end(t_data *data)
{
	pthread_mutex_lock(&data->end_mutex);
	data->simulation_end = 1;
	pthread_mutex_unlock(&data->end_mutex);
}
