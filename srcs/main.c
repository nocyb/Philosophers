/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:17:39 by njung             #+#    #+#             */
/*   Updated: 2025/04/10 14:32:47 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parsing(argc, argv);
	init_general(argc, argv, &data);
	init_mutexes(&data);
	init_philo(&data);
	monitor_philosophers(&data);
	free_resources(&data);
	return (0);
}
