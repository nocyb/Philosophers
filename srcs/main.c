/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:17:39 by njung             #+#    #+#             */
/*   Updated: 2025/03/25 16:41:49 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
    t_data data;

    parsing(ac, av);
    init_general(ac, av, &data);
    
    // Pour afficher le contenu sans lancer la simulation
    printf("nb_philo: %d\n", data.nb_philo);
    printf("time_to_die: %d\n", data.time_to_die);
    printf("time_to_eat: %d\n", data.time_to_eat);
    printf("time_to_sleep: %d\n", data.time_to_sleep);
    printf("nb_meals: %d\n", data.nb_meals);
    printf("nb_forks: %d\n", data.nb_forks);
    
    // init_philo(&data);
    // wait_for_philosophers(&data);  // a faire
    
    free_resources(&data);
    
    return (0);
}
