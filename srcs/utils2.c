/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:36:14 by njung             #+#    #+#             */
/*   Updated: 2025/04/04 18:42:37 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long get_current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        return (-1);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void precise_sleep(int milliseconds)
{
    long start_time;
    long end_time;

    start_time = get_current_time();
    end_time = start_time + milliseconds;
    while (get_current_time() < end_time)
        usleep(100);
}