/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:38:56 by njung             #+#    #+#             */
/*   Updated: 2025/03/27 10:43:24 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_letters(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if ((av[i][j] >= 'A' && av[i][j] <= 'Z')
             || (av[i][j] >= 'a' && av[i][j] <= 'z'))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}