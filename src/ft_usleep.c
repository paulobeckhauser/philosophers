/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:23:20 by pabeckha          #+#    #+#             */
/*   Updated: 2024/05/23 10:39:02 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void ft_usleep(int time)
{
    struct timeval start;
    struct timeval end;
    int diff;

    gettimeofday(&start, NULL);
    while (1)
    {
        gettimeofday(&end, NULL);
        diff = (end.tv_sec * 1000 + end.tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000);
        if (diff >= time)
            break ;
        usleep(100);
    }
}
