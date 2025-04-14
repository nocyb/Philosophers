/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:17:39 by njung             #+#    #+#             */
/*   Updated: 2025/04/14 11:38:05 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
    t_data	data;

    if (!parsing(argc, argv))
        return (1);
    if (!init_general(argc, argv, &data))
        return (1);
    init_mutexes(&data);
    init_philo(&data);
    monitor_philosophers(&data);
    free_resources(&data);
    return (0);
}
