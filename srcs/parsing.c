/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:17:47 by njung             #+#    #+#             */
/*   Updated: 2025/04/07 16:18:07 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_usage(void)
{
    write(1, "\033[31mWrong Usage!\n\033[0m", 22);
    write(1, "\033[32m/philosophers 1 2 3 4 5 =\n", 31);
    write(1, "1. Number of philo\n", 19);
    write(1, "2. Time To Die (in millsiseconds)\n", 34);
    write(1, "3. Time To Eat (in milliseconds)\n", 33);
    write(1, "4. Time To Sleep (in milliseconds)\n", 35);
    write(1, "\033[33m(optional) 5. Nb of meals\n\033[0m", 36);
    exit(0);
}

int check_limits(int ac, char **av)
{
    if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0)
    {
        write(1, "Negative value or 0 detected, error!\n", 37);
        return (0);
    }
    else if (ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
    {
        write(1, "Negative value or 0 detected, error!\n", 37);
        return (0);
    }
    else if (ac == 6)
    {
        if (ft_atoi(av[5]) <= 0)
        {
            write(1, "Negative value or 0 detected, error!\n", 37);
            return (0);
        }
    }
    return (1);
}

int check_limits2(int ac, char **av)
{
    (void)ac;
    if (ft_atoi(av[1]) >= INT_MAX)
    {
        write(1, "Too many philosophers!\n", 23);
        return (0);
    }
    else if (ft_atoi(av[2]) >= INT_MAX)
    {
        write(1, "Too much time to die!\n", 22);
        return (0);
    }
    else if (ft_atoi(av[3]) >= INT_MAX)
    {
        write(1, "Too much time to eat!\n", 22);
        return (0);
    }
    return (1);
}

int check_limits3(int ac, char **av)
{
    if (ft_atoi(av[4]) >= INT_MAX)
    {
        write(1, "Too much time to sleep!\n", 24);
        return (0);
    }
    if (ac == 6 && ft_atoi(av[5]) >= INT_MAX)
    {
        write(1, "Too much nb of meals!\n", 22);
        return (0);
    }
    return (1);
}

void parsing(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        ft_usage();
    else if (!check_letters(ac, av))
    {
        write(1, "Error, input must contains only numbers!\n", 41);
        ft_usage();
    }
    else if (!check_limits(ac, av))
        ft_usage();
    else if (!check_limits2(ac, av) || !check_limits3(ac, av))
        ft_usage();
}