/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:20 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/20 18:29:10 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
1) usleep the majority of time, not CPU intensive
2) refine last microsec with spinlock

*/


void ft_usleep(long usec, t_info *data)
{
    long start;
    long elapsed;
    long rem;

    start = gettime(MICROSECOND);
    
    while (gettime(MICROSECOND) - start < usec)
    {
        // 1) 
        if (check_simulation_finished(data))
            break ;

        elapsed = gettime(MICROSECOND) - start;
        rem = usec - elapsed;

        // to get a spinlock threshold

        if (rem > 1e3)
            usleep(rem / 2);

        else
        {
            // SPINLOCK
            while (gettime(MICROSECOND) - start < usec)
                ;
        }
    }
}